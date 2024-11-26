#ifndef OPENGL_ENGINE_GLRENDER_H
#define OPENGL_ENGINE_GLRENDER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class GLRender {
public:
    GLRender() = default;
    void init();
    void release();
    void render();
    void loop();

private:
    void processInput(GLFWwindow* window);
    void frameBufferNotify();

    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    GLFWwindow* window_;
    bool isLoop_ = false;
};



void GLRender::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window_ = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GLRender-windows", NULL, NULL);
    if (window_ == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window_);
    glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* window, int width, int height) {
         glViewport(0, 0, width, height); 
    });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

}

void GLRender::release() {
    isLoop_ = false;
}

void GLRender::render() {

}

void GLRender::loop() {
    if (isLoop_) {
        return;
    }

    isLoop_ = true;
    while (!glfwWindowShouldClose(window_) && isLoop_)
    {
        // input
        // -----
        processInput(window_);

        // render
        // ------
        render();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

void GLRender::processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
}



#endif // OPENGL_ENGINE__RENDER_H