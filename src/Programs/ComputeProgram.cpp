#include <Veritas/GPU/Programs/ComputeProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

using namespace Data;
using namespace Math;

#include <iostream>

uint32 createComputeShaderProgram(const String& icode) {
    String code = String("#version 310 es\n")
                + String("precision highp float;")
                + icode;

    char *source = (char*) code.getBuffer().getData();
    return glCreateShaderProgramv(GL_COMPUTE_SHADER, 1, &source);
}

ComputeProgram::ComputeProgram(const String &icode) : Resource(createComputeShaderProgram(icode)) {
    int32 linked;
    glGetProgramiv(getID(), GL_LINK_STATUS, &linked);
    if (!linked) {
        int length;
        glGetProgramiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetProgramInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
    }

    glGetProgramiv(getID(), GL_COMPUTE_WORK_GROUP_SIZE, (int32*) &groupSize);
}

ComputeProgram::~ComputeProgram() {
    glDeleteProgram(getID());
}

void ComputeProgram::compute(const uint32 work, Bindings bps) {
    compute(uvec3(work, 1, 1), bps);
}

void ComputeProgram::compute(const uvec2 &work, Bindings bps) {
    compute(uvec3(work.x, work.y, 1), bps);
}

void ComputeProgram::compute(const uvec3& work, Bindings bps) {
    for (const BindingPoint& bp : bps) glBindBufferBase(GL_SHADER_STORAGE_BUFFER, bp.getLocation(), bp.getResource().getID());
    glUseProgram(getID());
    glDispatchCompute(work.x / groupSize.x, work.y / groupSize.y, work.z / groupSize.z);
    for (const BindingPoint& bp : bps) glBindBufferBase(GL_SHADER_STORAGE_BUFFER, bp.getLocation(), bp.getResource().getID());
    glUseProgram(0);
}

const uvec3 &ComputeProgram::getGroupSize() const { return groupSize; }
