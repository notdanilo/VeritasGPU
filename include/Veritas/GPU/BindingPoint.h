#pragma once

#include "Resource.h"

#include <Veritas/Math/Math.h>

namespace Veritas {
    namespace GPU {
        using namespace Math;
        class BindingPoint {
            public:
                void bind() const;
                void unbind() const;
            protected:
                BindingPoint(std::function<void(void)> bind, std::function<void(void)> unbind);
            private:
                const std::function<void(void)> fbind, funbind;
        };
    }
}
