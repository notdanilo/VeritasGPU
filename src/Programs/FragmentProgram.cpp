#include <Veritas/GPU/Programs/FragmentProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using namespace Data;

#include <iostream>

uint32 createFragmentShaderProgram(const String& icode) {
    String code = String("#version 310 es\n")
                + String("precision highp float;")
                + icode;

    char *source = (char*) code.getBuffer().getData();
    return glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &source);
}

FragmentProgram::FragmentProgram(const String &icode) : Resource(createFragmentShaderProgram(icode)) {
    int32 linked;
    glGetProgramiv(getID(), GL_LINK_STATUS, &linked);
    if (!linked) {
        int length;
        glGetProgramiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetProgramInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
    }
}

FragmentProgram::~FragmentProgram() {
    glDeleteProgram(getID());
}
