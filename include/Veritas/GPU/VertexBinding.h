#pragma once

#include "BindingPoint.h"
#include "Buffer.h"

namespace Veritas {
    namespace GPU {
        class VertexBinding : public BindingPoint {
            public:
                VertexBinding(uint32 location, const Buffer& buffer, uint32 elementSize);
        };
    }
}
