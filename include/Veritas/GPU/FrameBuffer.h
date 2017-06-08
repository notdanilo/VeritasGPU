#pragma once

#include "Resource.h"

#include "Textures/Textures.h"

namespace Veritas {
    namespace GPU {
        class FrameBuffer : public Resource {
            public:
                FrameBuffer();
                ~FrameBuffer();

                void setColorBuffer(Textures::Texture2D& texture);
                void setDepthBuffer(Textures::Texture2D& texture);
                void setStencilBuffer(Textures::Texture2D& texture);

                Textures::Texture2D* getColorBuffer() const;
                Textures::Texture2D* getDepthBuffer() const;
                Textures::Texture2D* getStencilBuffer() const;
            private:
                friend class Context;
                FrameBuffer(uint32 id);

                Textures::Texture2D *colorBuffer, *depthBuffer, *stencilBuffer;
        };
    }
}
