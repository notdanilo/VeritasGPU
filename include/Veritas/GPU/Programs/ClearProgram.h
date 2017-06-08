#pragma once

#include <Veritas/Math/Math.h>
#include "../FrameBuffer.h"

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class ClearProgram {
                public:
                    void clear(FrameBuffer& fb, const Math::vec4& color, float32 depth, int32 stencil);
                    void clear(FrameBuffer& fb, const Math::vec4& color, float32 depth);
                    void clear(FrameBuffer& fb, const Math::vec4& color, int32 stencil);
                    void clear(FrameBuffer& fb, float32 depth, int32 stencil);
                    void clear(FrameBuffer& fb, const Math::vec4& color);
                    void clear(FrameBuffer& fb, float32 depth);
                    void clear(FrameBuffer& fb, int32 stencil);
            };
        }
    }
}
