#include <Veritas/GPU/Programs/ClearProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using namespace Math;

void ClearProgram::clear(FrameBuffer& fb, const vec4 &color, float32 depth, int32 stencil) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearColor(color.x, color.y, color.z, color.w);
    glClearDepthf(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, const vec4& color, float32 depth) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearColor(color.x, color.y, color.z, color.w);
    glClearDepthf(depth);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, const vec4& color, int32 stencil) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearColor(color.x, color.y, color.z, color.w);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, float32 depth, int32 stencil) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearDepthf(depth);
    glClearStencil(stencil);
    glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, const vec4 &color) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, float32 depth) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearDepthf(depth);
    glClear(GL_DEPTH_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ClearProgram::clear(FrameBuffer& fb, int32 stencil) {
    glBindFramebuffer(GL_FRAMEBUFFER, fb.getID());

    glClearStencil(stencil);
    glClear(GL_STENCIL_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
