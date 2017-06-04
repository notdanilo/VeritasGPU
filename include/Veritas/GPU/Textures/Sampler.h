#pragma once

#include "../Resource.h"

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class Sampler : public Resource {
                public:
                    enum WRAPPING { REPEAT, MIRRORED_REPEAT, CLAMP_TO_EDGE, CLAMP_TO_BORDER };
                    enum FILTERING { NEAREST, LINEAR, NEAREST_MIPMAP_NEAREST, LINEAR_MIPMAP_NEAREST, NEAREST_MIPMAP_LINEAR, LINEAR_MIPMAP_LINEAR };

                    Sampler(FILTERING in = LINEAR, FILTERING out = LINEAR, WRAPPING x = REPEAT, WRAPPING y = REPEAT, WRAPPING z = REPEAT);
                    ~Sampler();

                    void setWrapping(WRAPPING x, WRAPPING y, WRAPPING z);
                    void setFiltering(FILTERING in, FILTERING out);
            };
        }
    }
}
