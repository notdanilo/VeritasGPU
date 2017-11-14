#include <Veritas/GPU/Programs/VertexProgram.h>

#include <Veritas/GPU/Definitions.h>

#include <iostream>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using std::string;

uint32 createVertexShaderProgram(const string& icode) {
    string code = string("#version 320 es\n")
                // #warning https://stackoverflow.com/questions/5366416/in-opengl-es-2-0-glsl-where-do-you-need-precision-specifiers
                // + String("precision highp float;")
                + icode;

    const char *source = code.c_str();
    return glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &source);
}

VertexProgram::VertexProgram(const string &icode) : Resource(createVertexShaderProgram(icode)) {
    int32 linked;
    glGetProgramiv(getID(), GL_LINK_STATUS, &linked);
    if (!linked) {
        int length;
        glGetProgramiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char *log = new char[length];
        glGetProgramInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
        delete[] log;
    }
}

VertexProgram::~VertexProgram() {
    glDeleteProgram(getID());
}
