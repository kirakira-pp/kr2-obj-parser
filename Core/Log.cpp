#include "Log.h"

#include <iostream>
#include <ctime>

// TODO: Add logger level filter

Log g_Logger;

const std::string LogLevelName[Log::LogLevel::LogLevelCount] = {"Trace", "Debug", "Info", "Warn", "Error", "Critical"};

struct Log::Impl
{
    std::string formatLog(Log::LogLevel level, const char *file, int line, const char *function, const std::string &s);
};

Log::Log()
{
    m_Impl = std::make_unique<Impl>();

    setvbuf(stdout, NULL, _IONBF, 0);
}

Log::~Log()
{
}

void Log::LogMessageImpl(Log::LogLevel level, const char *file, int line, const char *function, const std::string &s)
{
    std::cout << m_Impl->formatLog(level, file, line, function, s) << '\n';
}

std::string Log::Impl::formatLog(Log::LogLevel level, const char *file, int line, const char *function, const std::string &s)
{
    std::string_view f(file);
    // strip parent path
    auto i = f.find_last_of('/');
    f = f.substr(i+1, f.size()-i);

    return fmt::format("[{}][{}:{}] {}", LogLevelName[level], f, line, s);
}
