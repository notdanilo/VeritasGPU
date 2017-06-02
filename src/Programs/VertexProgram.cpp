#include <Veritas/GPU/Programs/VertexProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using namespace Data;

#include <iostream>

uint32 createVertexShaderProgram(const String& icode) {
    String code = String("#version 310 es\n")
                + String("#extension GL_OES_shader_io_blocks : enable\n")
                + String("precision highp float;")
                + icode;

    char *source = (char*) code.getBuffer().getData();
    return glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &source);
}

VertexProgram::VertexProgram(const String &icode) : Resource(createVertexShaderProgram(icode)) {
    int32 linked;
    glGetProgramiv(getID(), GL_LINK_STATUS, &linked);
    if (!linked) {
        int length;
        glGetProgramiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetProgramInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
    }

    for (int i = 0;; i++) {
        GLsizei length = 1024;
        GLchar name[length];
        GLint size;
        GLenum type;
        glGetActiveAttrib(getID(), i, length, &length, &size, &type, name);
        if (glGetError()) break;
        uint32 location = glGetAttribLocation(getID(), name);

        switch (type) {
            case GL_FLOAT: size *= 1; break;
            case GL_FLOAT_VEC2: size *= 2; break;
            case GL_FLOAT_VEC3: size *= 3; break;
            case GL_FLOAT_VEC4: size *= 4; break;
            case GL_FLOAT_MAT2: size *= 4; break;
            case GL_FLOAT_MAT3: size *= 9; break;
            case GL_FLOAT_MAT4: size *= 16; break;
            case GL_FLOAT_MAT2x3: size *= 6; break;
            case GL_FLOAT_MAT2x4: size *= 8; break;
            case GL_FLOAT_MAT3x2: size *= 6; break;
            case GL_FLOAT_MAT3x4: size *= 12; break;
            case GL_FLOAT_MAT4x2: size *= 8; break;
            case GL_FLOAT_MAT4x3: size *= 12; break;
            case GL_INT: size *= 1; break;
            case GL_INT_VEC2: size *= 2; break;
            case GL_INT_VEC3: size *= 3; break;
            case GL_INT_VEC4: size *= 4; break;
            case GL_UNSIGNED_INT: size *= 1; break;
            case GL_UNSIGNED_INT_VEC2: size *= 2; break;
            case GL_UNSIGNED_INT_VEC3: size *= 3; break;
            case GL_UNSIGNED_INT_VEC4: size *= 4; break;
            /* not supported on gles
            case GL_DOUBLE: break;
            case GL_DOUBLE_VEC2: break;
            case GL_DOUBLE_VEC3: break;
            case GL_DOUBLE_VEC4: break;
            case GL_DOUBLE_MAT2: break;
            case GL_DOUBLE_MAT3: break;
            case GL_DOUBLE_MAT4: break;
            case GL_DOUBLE_MAT2x3: break;
            case GL_DOUBLE_MAT2x4: break;
            case GL_DOUBLE_MAT3x2: break;
            case GL_DOUBLE_MAT3x4: break;
            case GL_DOUBLE_MAT4x2: break;
            case GL_DOUBLE_MAT4x3: break;
            */
        }

        attributes.push_back(std::pair<int32,uint32>(location, size));
    }
}

VertexProgram::~VertexProgram() {
    glDeleteProgram(getID());
}

uint32 VertexProgram::getLocationSize(uint32 location) const {
    for (auto& attribute : attributes)
        if (attribute.first == location)
            return attribute.second;
    return 0;
}
