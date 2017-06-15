#include <Veritas/GPU/Context.h>
#include <Veritas/Definitions/Definitions.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

using namespace OpenGL;

using namespace Data;

Context::Context(uint64 windowHandle, const String &version) :
    framebuffer(0)
{
    context = new OpenGLESContext(windowHandle, 3, 2);
    OpenGLESContext::push();

    makeCurrent();
    GLint dim[4] = { 0 };
    glGetIntegerv(GL_VIEWPORT, dim);
    framebuffer = new FrameBuffer(0, dim[2], dim[3]);

    OpenGLESContext::pop();
}
Context::~Context() {
    delete context;
}

void Context::makeCurrent() {
    context->makeCurrent();
}
void Context::swapBuffers() {
    context->swapBuffers();
}

FrameBuffer& Context::getMainFrameBuffer() { return *framebuffer; }
