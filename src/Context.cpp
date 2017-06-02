#include <Veritas/GPU/Context.h>
#include <Veritas/Definitions/Definitions.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

using namespace OpenGL;

using namespace Data;

Context::Context(uint64 windowHandle, const String &version) {
    context = new OpenGLESContext(windowHandle, 3, 1);
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
