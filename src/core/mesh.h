#ifndef OPENGL_ENGINE_MESH_H
#define OPENGL_ENGINE_MESH_H

#include <glad/glad.h>
#include <vector>

class Vector4;
struct Mesh {
public:
    Mesh() = default;

    ~Mesh() {

    }

    void bind() {
        unbind();

        // 生成对应资源，创建 vao vbo ebo
        glGenVertexArrays(1, &vao_);
        glGenBuffers(1, &vbo_);
        glGenBuffers(1, &ebo_);

        // 绑定 VAO，之后的顶点缓冲区和属性配置都记录到当前绑定的 VAO 中。
        glBindVertexArray(vao_);
        // 绑定 VBO，告诉 OpenGL 将所有顶点缓冲区操作应用于这个 VBO。
        glBindBuffer(GL_ARRAY_BUFFER, vbo_); 
        // 将顶点数据上传到显存，指定了缓冲区大小、数据来源和使用模式
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vector4) * m_positions.size(), m_positions.data(), GL_STATIC_DRAW);

        // 绑定 EBO，告诉 OpenGL 将索引缓冲区操作应用于这个 EBO。
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
        // 将索引数据上传到显存。
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * m_indices.size(), m_indices.data(), GL_STATIC_DRAW);
        
        // 配置顶点属性
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vector4), (void*)0);
        // 启用顶点属性 0
        glEnableVertexAttribArray(0);
    }

    void unbind() {
        if (vao_ != GL_INVALID_VALUE) {
            glDeleteVertexArrays(1, &vao_);
            vao_ = GL_INVALID_VALUE;
        }

        if (vbo_ != GL_INVALID_VALUE) {
            glDeleteBuffers(1, &vbo_);
            vbo_ = GL_INVALID_VALUE;
        }

        if (ebo_ != GL_INVALID_VALUE) {
            glDeleteBuffers(1, &ebo_);
            ebo_ = GL_INVALID_VALUE;
        }
    }

    bool apply() {
        if (vao_ != GL_INVALID_VALUE)
        {
            glBindVertexArray(vao_);
            return true;
        }

        return false;
    }
    
private:
    std::vector<Vector4> m_positions;
    std::vector<uint32_t> m_indices;

    GLuint vbo_ = GL_INVALID_VALUE;
    GLuint vao_ = GL_INVALID_VALUE;
    GLuint ebo_ = GL_INVALID_VALUE;
};

class Vector4
{
public:
    Vector4() = default;
    Vector4(const Vector4&) = default;
    Vector4(Vector4&&) = default;
    Vector4& operator=(const Vector4&) = default;
    Vector4(float inputX, float inputY, float inputZ, float inputW) : x(inputX), y(inputY), z(inputZ), w(inputW) {}

    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;
};

// https://www.zhihu.com/column/c_1730233106223792128

#endif // OPENGL_ENGINE_MESH_H