#pragma once

#include "Resource.h"

#include "Textures/Textures.h"

namespace Veritas {
    namespace GPU {
        class FrameBuffer : public Resource {
            public:
                FrameBuffer(uint32 width, uint32 height);
                ~FrameBuffer();

                // It's only copying the colorbuffer
                void copy(const FrameBuffer& framebuffer);

                uint32 getWidth() const;
                uint32 getHeight() const;

                void setColorBuffer(Textures::Texture2D& texture);
                void setDepthBuffer(Textures::Texture2D& texture);
                void setStencilBuffer(Textures::Texture2D& texture);

                Textures::Texture2D* getColorBuffer() const;
                Textures::Texture2D* getDepthBuffer() const;
                Textures::Texture2D* getStencilBuffer() const;
            private:
                uint32 width, height;
                friend class Context;
                FrameBuffer(uint32 id, uint32 width, uint32 height);

                Textures::Texture2D *colorBuffer, *depthBuffer, *stencilBuffer;
        };
    }
}
