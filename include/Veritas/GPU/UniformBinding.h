#pragma once

#include <Veritas/GPU/BindingPoint.h>

namespace Veritas {
    namespace GPU {
        class UniformBinding : public BindingPoint {
            public:
                UniformBinding(uint32 location, const Resource& program, float32 value);
                UniformBinding(uint32 location, const Resource& program, int32 value);
        };
    }
}
