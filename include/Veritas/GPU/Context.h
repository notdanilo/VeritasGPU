#pragma once

#include <Veritas/Data/String.h>
#include <Veritas/OpenGL/OpenGLESContext.h>

namespace Veritas {
    namespace GPU {
        class Context {
            public:
                Context(uint64 windowHandle, const Data::String& version);
                ~Context();

                void makeCurrent();
                void swapBuffers();
            private:
                OpenGL::OpenGLESContext* context;

                    /*
                    void makeCurrent();
                    void swapBuffers(Buffers::FrameBuffer *fb, Math::vec2 position = Math::vec2(0.0));
                    void swapBuffers(Buffers::FrameBuffer *fb, Math::vec2 position, Math::vec2 dimension);

                    RenderProgram::VertexArrayObject* getQuad();
                    RenderProgram::VertexArrayObject* getCube();
                    RenderProgram::VertexArrayObject* getSphere();

                    ClearProgram* getClearProgram() const;

                    static Context* getCurrent();

                    Buffers::FrameBuffer* getDefaultFrameBuffer() const;

                private:
                    void *data;
                    void (*fmakeCurrent)(void *data);
                    void (*fswapBuffers)(void *data);

                    uint32 viewportWidth, viewportHeight;

                    thread_local static Context* current;

                    ClearProgram* clearProgram;

                    Buffers::FrameBuffer* defaultFrameBuffer;

                    friend class Samplers::Sampler1D;
                    friend class Samplers::Sampler2D;
                    friend class Samplers::Sampler3D;
                    friend class Samplers::SamplerCube;
                    Buffers::FrameBuffer *pixelReadFrameBuffer;

                    friend class ClearProgram; ClearProgram::GPU GPUClearProgram;
                    friend class Program; Program* boundProgram;

                    friend class Buffers::FrameBuffer; Buffers::FrameBuffer* boundFrameBuffer;
                    friend class Buffers::IndexBuffer; Buffers::IndexBuffer* boundIndexBuffer;
                    friend class Buffers::VertexBuffer; Buffers::VertexBuffer* boundVertexBuffer;

                    friend class RenderProgram; RenderProgram::GPU GPURenderProgram;

                    uint8 boundSamplerUnit;
                    friend class Samplers::Sampler; Samplers::Sampler *boundSampler[8],*boundImage[8];

                    bool isMultisampling;

                    RenderProgram::VertexArrayObject *quad, *cube, *sphere;

                    RenderProgram *copyProgram;
                    */
        };
    }
}
