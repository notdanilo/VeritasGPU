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
            };
        }
    }
}
