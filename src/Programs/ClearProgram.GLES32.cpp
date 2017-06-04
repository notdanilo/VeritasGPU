#include <Veritas/GPU/Programs/ClearProgram.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;

using namespace Math;

void ClearProgram::clear(const vec4 &color, float32 depth, int32 stencil) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClearDepthf(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void ClearProgram::clear(const vec4& color, float32 depth) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClearDepthf(depth);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ClearProgram::clear(const vec4& color, int32 stencil) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void ClearProgram::clear(float32 depth, int32 stencil) {
    glClearDepthf(depth);
    glClearStencil(stencil);
    glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void ClearProgram::clear(const vec4 &color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void ClearProgram::clear(float32 depth) {
    glClearDepthf(depth);
    glClear(GL_DEPTH_BUFFER_BIT);
}

void ClearProgram::clear(int32 stencil) {
    glClearStencil(stencil);
    glClear(GL_STENCIL_BUFFER_BIT);
}
