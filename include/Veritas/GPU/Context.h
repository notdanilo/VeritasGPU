#pragma once

#include <Veritas/Data/String.h>
#include <Veritas/OpenGL/OpenGLESContext.h>

#include "FrameBuffer.h"

namespace Veritas {
    namespace GPU {
        class Context {
            public:
                Context(uint64 windowHandle, const Data::String& version);
                Context(Context&& move);
                Context(const Context& copy) = delete;
                ~Context();

                void operator=(Context&& move);
                void operator=(const Context& copy);

                Context& makeCurrent();
                Context &swapBuffers();

                FrameBuffer& getMainFrameBuffer();
            private:
                OpenGL::OpenGLESContext* context;
                FrameBuffer* framebuffer;
        };
    }
}
