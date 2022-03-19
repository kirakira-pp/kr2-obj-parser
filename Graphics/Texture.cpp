#include "Texture.h"
#include "Core/Log.h"

#include <stb_image.h>
#include <filesystem>

struct Image
{
    int width = 0, height = 0, numChannel = 0;
    unsigned char *bytes = nullptr;

    Image() = default;
    ~Image()
    {
        if(bytes)
            stbi_image_free(bytes);
    }
};

Ref<Image> LoadImage(const std::filesystem::path &path)
{
    Ref<Image> image = MakeRef<Image>();
    stbi_set_flip_vertically_on_load(true);

    if(!std::filesystem::exists(path))
    {
        LOG_ERROR("Failed to load image: {}. Reason: Do not exist", path.string());
        return image;
    }

    image->bytes = stbi_load(path.string().c_str(), &image->width, &image->height, &image->numChannel, 0);

    if(!image->bytes)
    {
        LOG_ERROR("Failed to load image: {}. Reason: stbi_load() error", path.string());
        return image;
    }

    return image;
}

Texture::Texture(std::filesystem::path path, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType)
{
    auto image = LoadImage(path);

    m_Type = textureType;

    glGenTextures(1, &m_ID);
    glActiveTexture(slot);
    glBindTexture(m_Type, m_ID);

    glTexParameteri(m_Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(m_Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(m_Type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(m_Type, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(m_Type, 0, GL_RGBA, image->width, image->height, 0, format, pixelType, image->bytes);

    glGenerateMipmap(m_Type);
    glBindTexture(m_Type, 0);
}

Texture::~Texture()
{
    if(m_ID)
        Delete();
}

void Texture::TexUnit(const Ref<Shader> &shader, const char *uniform, GLuint unit)
{
    shader->Activate();
    glUniform1i(glGetUniformLocation(shader->GetID(), uniform), unit);
}

void Texture::Delete()
{
    glDeleteTextures(1, &m_ID);
}

void Texture::Bind()
{
    glBindTexture(m_Type, m_ID);
}

void Texture::Unbind()
{
    glBindTexture(m_Type, 0);
}
