#pragma once

#include <Veritas/GPU/Textures/Texture.h>
#include <Veritas/GPU/BindingPoint.h>

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class ImageBinding : public BindingPoint {
                public:
                    enum PERMISSION { WRITE = 1, READ = 2 };

                    ImageBinding(uint32 location, const Texture& texture, PERMISSION permission);
            };
        }
    }
}
