#include "gl_render.h"
#include "sharder.h"
#include <string>

const std::string VertexPath = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
    
const std::string VertexPath = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

void initSharder() {
    Shader sharder();
}

int main() {
    GLRender render;
    render.init();
    render.setRenderCallback([](){
        
    });
    render.loop();

    return 0;
}