#pragma once

#include "../Resource.h"
#include "Texture.h"

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class Texture2D : public Texture {
                public:
                    Texture2D(uint32 width, uint32 height, ELEMENTS elements, TYPE type, const void* data = 0);

                    uint32 getWidth() const;
                    uint32 getHeight() const;
                private:
                    uint32 width, height;                    
            };
        }
    }
}
