#pragma once

#include "../Resource.h"
#include "Texture.h"

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class Texture3D : public Texture {
                public:
                    Texture3D(uint32 width, uint32 height, uint32 depth, ELEMENTS elements, TYPE type, const void* data);

                    uint32 getWidth() const;
                    uint32 getHeight() const;
                    uint32 getDepth() const;
                private:
                    uint32 width, height, depth;
            };
        }
    }
}
