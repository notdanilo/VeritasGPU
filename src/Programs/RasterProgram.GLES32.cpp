#include <Veritas/GPU/Programs/RasterProgram.h>

#include <Veritas/GPU/Definitions.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

#include <iostream>

uint32 createProgramPipeline() {
    uint32 program;
    glGenProgramPipelines(1, &program);
    return program;
}

RasterProgram::RasterProgram(const VertexProgram& vp, const FragmentProgram &fp) : Program(createProgramPipeline()), vp(vp), fp(fp) {
    glUseProgramStages(getID(), GL_VERTEX_SHADER_BIT, vp.getID());
    glUseProgramStages(getID(), GL_FRAGMENT_SHADER_BIT, fp.getID());

    glValidateProgramPipeline(getID());
    int32 valid;
    glGetProgramPipelineiv(getID(), GL_VALIDATE_STATUS, &valid);
    if (!valid) {
        int32 length;
        glGetProgramPipelineiv(getID(), GL_INFO_LOG_LENGTH, &length);
        char *log = new char[length];
        glGetProgramPipelineInfoLog(getID(), length, &length, log);
        std::cerr << log << std::endl;
        delete[] log;
    }
}

RasterProgram::~RasterProgram() {
    glDeleteProgramPipelines(1, &getID());
}

void RasterProgram::points(FrameBuffer& fb, uint32 npoints, bool depthTesting, const Bindings &bps) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glBindProgramPipeline(getID());
    for (auto bp : bps) bp.bind();

    if (depthTesting) glEnable(GL_DEPTH_TEST);

    glEnable(GL_PROGRAM_POINT_SIZE);

    glDrawArrays(GL_POINTS, 0, npoints);

    glDisable(GL_PROGRAM_POINT_SIZE);

    if (depthTesting) glDisable(GL_DEPTH_TEST);

    for (auto bp : bps) bp.unbind();
    glBindProgramPipeline(0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RasterProgram::lines(FrameBuffer& fb, uint32 nlines, bool depthTesting, const Bindings &bps) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glBindProgramPipeline(getID());
    for (auto bp : bps) bp.bind();

    if (depthTesting) glEnable(GL_DEPTH_TEST);

    glDrawArrays(GL_LINE_STRIP, 0, nlines + 1);

    if (depthTesting) glDisable(GL_DEPTH_TEST);

    for (auto bp : bps) bp.unbind();
    glBindProgramPipeline(0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RasterProgram::lines(FrameBuffer& fb, uint32 nlines, bool depthTesting, const IndexBinding &indices, const Bindings &bps) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glBindProgramPipeline(getID());
    for (auto bp : bps) bp.bind();

    indices.bind();

    uint32 type = 0;
    switch (indices.getType()) {
        case IndexBinding::UINT8:  type = GL_UNSIGNED_BYTE; break;
        case IndexBinding::UINT16: type = GL_UNSIGNED_SHORT; break;
        case IndexBinding::UINT32: type = GL_UNSIGNED_INT; break;
    }

    if (depthTesting) glEnable(GL_DEPTH_TEST);

    glDrawElements(GL_LINES, nlines * 2, type, 0);

    if (depthTesting) glDisable(GL_DEPTH_TEST);

    for (auto bp : bps) bp.unbind();
    glBindProgramPipeline(0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RasterProgram::triangles(FrameBuffer& fb, uint32 ntriangles, bool depthTesting, bool faceCulling, const IndexBinding &indices, const Bindings& bps) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glBindProgramPipeline(getID());
    for (auto bp : bps) bp.bind();

    indices.bind();

    uint32 type = 0;
    switch (indices.getType()) {
        case IndexBinding::UINT8:  type = GL_UNSIGNED_BYTE; break;
        case IndexBinding::UINT16: type = GL_UNSIGNED_SHORT; break;
        case IndexBinding::UINT32: type = GL_UNSIGNED_INT; break;
    }

    if (faceCulling) glEnable(GL_CULL_FACE);
    if (depthTesting) glEnable(GL_DEPTH_TEST);

    glDrawElements(GL_TRIANGLES, ntriangles * 3, type, 0);

    if (depthTesting) glDisable(GL_DEPTH_TEST);
    if (faceCulling) glDisable(GL_CULL_FACE);

    for (auto bp : bps) bp.unbind();
    glBindProgramPipeline(0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
