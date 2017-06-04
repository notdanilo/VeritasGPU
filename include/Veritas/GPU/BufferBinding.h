#pragma once

#include "BindingPoint.h"
#include "Buffer.h"

namespace Veritas {
    namespace GPU {
        class BufferBinding : public BindingPoint {
            public:
                BufferBinding(uint32 location, const Buffer& buffer);
        };
    }
}
