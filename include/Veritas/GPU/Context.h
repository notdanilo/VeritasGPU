#pragma once

#include <Veritas/OpenGL/OpenGLContext.h>

#include <Veritas/GPU/FrameBuffer.h>

#include <string>

namespace Veritas {
    namespace GPU {
        class Context {
            public:
                Context(uint64 windowHandle, const std::string& version);
                Context(Context&& move);
                Context(const Context& copy) = delete;
                ~Context();

                void operator=(Context&& move);
                void operator=(const Context& copy);

                Context& makeCurrent();
                Context& swapBuffers(FrameBuffer& framebuffer);
            private:
                FrameBuffer& getMainFrameBuffer();

                OpenGL::OpenGLContext* context;
                FrameBuffer* framebuffer;
        };
    }
}
