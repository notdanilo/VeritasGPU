#pragma once

#include "BindingPoint.h"
#include "Buffer.h"

namespace Veritas {
    namespace GPU {
        class IndexBinding : public BindingPoint {
            public:
                enum TYPE { UINT8, UINT16, UINT32 };
                IndexBinding(const Buffer& buffer, TYPE type);

                TYPE getType() const;
            private:
                TYPE type;
        };
    }
}
