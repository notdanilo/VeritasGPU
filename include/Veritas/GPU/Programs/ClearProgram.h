#pragma once

#include <Veritas/Math/Math.h>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class ClearProgram {
                public:
                    void clear(const Math::vec4& color, float32 depth, int32 stencil);
                    void clear(const Math::vec4& color, float32 depth);
                    void clear(const Math::vec4& color, int32 stencil);
                    void clear(float32 depth, int32 stencil);
                    void clear(const Math::vec4& color);
                    void clear(float32 depth);
                    void clear(int32 stencil);
            };
        }
    }
}
