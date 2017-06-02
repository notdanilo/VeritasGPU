#include <Veritas/GPU/Programs/RenderProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using namespace Data;

#include <iostream>

uint32 createProgramPipeline() {
    uint32 program;
    glGenProgramPipelines(1, &program);
    return program;
}

RenderProgram::RenderProgram(const VertexProgram& vp, const FragmentProgram &fp) : Resource(createProgramPipeline()), vp(vp), fp(fp) {
    glUseProgramStages(getID(), GL_VERTEX_SHADER_BIT, vp.getID());
    glUseProgramStages(getID(), GL_FRAGMENT_SHADER_BIT, fp.getID());

    glValidateProgramPipeline(getID());
    int32 valid;
    glGetProgramPipelineiv(getID(), GL_VALIDATE_STATUS, &valid);
    if (!valid) {
        int32 length;
        glGetProgramPipelineiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetProgramPipelineInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
    }
}

RenderProgram::~RenderProgram() {
    glDeleteProgramPipelines(1, &getID());
}

void RenderProgram::points(uint32 ammount, Bindings bps) {
    glBindProgramPipeline(getID());
    for (auto& bp : bps) {
        glBindBuffer(GL_ARRAY_BUFFER, bp.getResource().getID());

        glVertexAttribPointer(bp.getLocation(), vp.getLocationSize(bp.getLocation()), GL_FLOAT, false, 0, 0);
        glEnableVertexAttribArray(bp.getLocation());
    }

    glDrawArrays(GL_POINTS, 0, ammount);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindProgramPipeline(0);
}
