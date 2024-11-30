#include "gl_render.h"
#include "sharder.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <string>

/**
 * 接受 float 数组（数组本身也可以封装，设置一个 vec1 vec2 vec3 vec4 表示一个点可能有多个属性，然后再塞入vector中）
 * 这个数组传递到 mesh 里面，根据数组的元素数量，是否启动从而得到了一个 vao 其与 mesh 作绑定
 * 
 * - enable position
 * - enable colors
 * - enable texture
 * - enable line
 * ...
 * 
 * 设计成 build 模式
*/
int initVAO() {
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    return VAO;
}

/**
 * 纹理资源可以另外封装使用
*/
void initTexture(unsigned int& id, const std::string path) {
    int width, height, nrChannels;
    // texture 2
    // ---------
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << error << std::endl;
    }
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL Error after glTexImage2D: " << error << std::endl;
        }
        glGenerateMipmap(GL_TEXTURE_2D);
        error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL Error: " << error << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void initTexture(unsigned int& texture1, unsigned int& texture2) {
    std::string path1 = "..\\resource\\image\\container.png";
    std::string path2 = "..\\resource\\image\\awesomeface.png";
    initTexture(texture1, path1);
    initTexture(texture2, path2);
}

int main() {
    unsigned int texture1, texture2;
    GLRender render;
    render.init();
    
    Shader sharder("..\\resource\\shader\\texture\\texture.vs", "..\\resource\\shader\\texture\\texture.fs");
    int VAO = initVAO();
    sharder.use();
    std::cout << "VAO is " << VAO;
    // 设置纹理单元，并将其传递给着色器的采样器
    initTexture(texture1, texture2);
    sharder.setInt("texture1", 0);
    sharder.setInt("texture2", 1);

    render.setRenderCallback([=](){
        // 激活第一个纹理单元
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        // 激活第二个纹理单元
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        // 绘制物体
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    });

    render.loop();
    

    return 0;
}