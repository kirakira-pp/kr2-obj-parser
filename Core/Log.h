#pragma once
#ifndef KR2_OBJ_PARSER_LOG_H
#define KR2_OBJ_PARSER_LOG_H

#include <string>
#include <memory>
#include <fmt/format.h>

#define LOG_TRACE(...) g_Logger.LogMessage(Log::LogLevelTrace, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LOG_DEBUG(...) g_Logger.LogMessage(Log::LogLevelDebug, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LOG_INFO(...) g_Logger.LogMessage(Log::LogLevelInfo, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LOG_WARN(...) g_Logger.LogMessage(Log::LogLevelWarn, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LOG_ERROR(...) g_Logger.LogMessage(Log::LogLevelError, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LOG_CRITICAL(...) g_Logger.LogMessage(Log::LogLevelCritical, __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)

class Log
{
public:
    Log();
    ~Log();

    enum LogLevel
    {
        LogLevelTrace = 0,
        LogLevelDebug,
        LogLevelInfo,
        LogLevelWarn,
        LogLevelError,
        LogLevelCritical,
        LogLevelCount
    };

    template<typename ... Args>
    void LogMessage(LogLevel level, const char* file, int line, const char* function, const std::string &fmt, Args && ... args)
    {
        auto formatted = fmt::vformat(fmt, fmt::make_format_args(std::forward<Args>(args)...));
        LogMessageImpl(level, file, line, function, formatted);
    }

    void LogMessage(LogLevel level, const char* file, int line, const char* function, const std::string &s)
    {
        LogMessageImpl(level, file, line, function, s);
    }
private:
    void LogMessageImpl(LogLevel level, const char* file, int line, const char* function, const std::string &s);

    struct Impl;
    friend class Impl;
    std::unique_ptr<Impl> m_Impl;
};

extern Log g_Logger;

#endif //KR2_OBJ_PARSER_LOG_H