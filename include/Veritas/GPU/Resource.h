#pragma once

#include <Veritas/Definitions/Definitions.h>

namespace Veritas {
    namespace GPU {
        class Resource {
            public:
                const uint32& getID() const;
            protected:
                Resource(uint32 id);
            private:
                uint32 id;
        };
    }
}
