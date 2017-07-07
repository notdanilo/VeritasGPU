#include <Veritas/GPU/Context.h>
#include <Veritas/Definitions/Definitions.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

using namespace OpenGL;

using std::string;

Context::Context(uint64 windowHandle, const string &version) :
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
Context::Context(Context &&move)
    : framebuffer(move.framebuffer)
    , context(move.context)
{
    move.framebuffer = 0;
    move.context = 0;
}

Context::~Context() {
    delete framebuffer;
    delete context;
}

Context &Context::makeCurrent() {
    context->makeCurrent();
    return *this;
}

Context &Context::swapBuffers(FrameBuffer &framebuffer) {
    getMainFrameBuffer().copy(framebuffer);
    context->swapBuffers();
    return *this;
}

FrameBuffer& Context::getMainFrameBuffer() { return *framebuffer; }
