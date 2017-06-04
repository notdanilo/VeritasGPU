#pragma once

#include <Veritas/GPU/Textures/Textures.h>
#include <Veritas/GPU/UniformBinding.h>

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class SamplerBinding : public BindingPoint {
                public:
                    SamplerBinding(uint32 location, const Sampler& sampler, const Resource& program, const Texture& texture, uint32 unit);
                private:
                    UniformBinding uniform;
            };
        }
    }
}
