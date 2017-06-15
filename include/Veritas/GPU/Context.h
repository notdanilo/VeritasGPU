#pragma once

#include <Veritas/Data/String.h>
#include <Veritas/OpenGL/OpenGLESContext.h>

#include "FrameBuffer.h"

namespace Veritas {
    namespace GPU {
        class Context {
            public:
                Context(uint64 windowHandle, const Data::String& version);
                ~Context();

                void makeCurrent();
                void swapBuffers();

                FrameBuffer& getMainFrameBuffer();
            private:
                OpenGL::OpenGLESContext* context;
                FrameBuffer* framebuffer;
        };
    }
}
