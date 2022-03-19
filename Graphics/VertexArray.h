#pragma once
#ifndef KR2_OBJ_PARSER_VERTEXARRAY_H
#define KR2_OBJ_PARSER_VERTEXARRAY_H

#include <glad/glad.h>

#include "Ref.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();
    void Delete();

    void Bind() const;
    void Unbind() const;

    void BindVertexBuffer(const Ref<VertexBuffer> &vbo);
    void BindIndexBuffer(const Ref<IndexBuffer> &ibo);

    // TODO: use glsl parser?
    void BindVertexAttribute(GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
private:
    GLuint m_ID;
    Ref<VertexBuffer> m_VertexBuffer;
};


#endif //KR2_OBJ_PARSER_VERTEXARRAY_H