#pragma once

#include <Veritas/Definitions/Definitions.h>
#include "Resource.h"

namespace Veritas {
    namespace GPU {
        class Buffer : public Resource {
            public:
                Buffer(uint32 size);
                Buffer(uint32 size, void *data);
                ~Buffer();

                uint32 getSize() const;

                void write(void *data, uint32 length);
                void write(void *data, uint32 offset, uint32 length);
                void read(void *data, uint32 offset, uint32 length);
                void read(void *data, uint32 length);
        };

    }
}
