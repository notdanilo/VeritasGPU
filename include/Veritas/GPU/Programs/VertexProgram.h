#pragma once

#include <Veritas/Data/String.h>
#include "../Resource.h"

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class VertexProgram : public Resource {
                public:
                    VertexProgram(const Data::String& code);
                    ~VertexProgram();

                    uint32 getLocationSize(uint32 location) const;
                private:
                    friend class RenderProgram;
                    std::vector<std::pair<int32, uint32>> attributes;
            };
        }
    }
}
