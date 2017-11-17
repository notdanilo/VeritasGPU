#pragma once

#include <Veritas/OpenGL/OpenGL.h>

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
                void operator=(const Context& copy) = delete;

                Context& makeCurrent();
                Context& swapBuffers(FrameBuffer& framebuffer);
            private:
                FrameBuffer& getMainFrameBuffer();

                OpenGL::IOpenGLContext* context;
                FrameBuffer* framebuffer;
        };
    }
}
