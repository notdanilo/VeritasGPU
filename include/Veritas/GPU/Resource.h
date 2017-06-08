#pragma once

#include <Veritas/Definitions/Definitions.h>

namespace Veritas {
    namespace GPU {
        class Resource {
            public:
                Resource(const Resource& resource) = delete;
                void operator=(const Resource& resource) = delete;

                const uint32& getID() const;
            protected:
                Resource(uint32 id);
            private:
                uint32 id;
        };
    }
}
