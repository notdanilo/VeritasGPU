#pragma once

#include "Resource.h"

namespace Veritas {
    namespace GPU {
        class BindingPoint {
            public:
                BindingPoint(const Resource& resource, uint32 location);

                const Resource& getResource() const;
                uint32 getLocation() const;
            private:
                const Resource& resource;
                const uint32 location;
        };
    }
}
