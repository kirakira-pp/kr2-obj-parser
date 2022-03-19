#pragma once
#ifndef KR2_OBJ_PARSER_VERTEXBUFFER_H
#define KR2_OBJ_PARSER_VERTEXBUFFER_H

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer();
    VertexBuffer(GLfloat *vertices, GLsizeiptr size);
    ~VertexBuffer();
    void Delete();

    void Store(GLfloat *vertices, GLsizeiptr size);

    void Bind() const;
    void Unbind() const;

    static void Clear();
private:
    GLuint m_ID;
};

#endif //KR2_OBJ_PARSER_VERTEXBUFFER_H