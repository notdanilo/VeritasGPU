#pragma once

#include <Veritas/GPU/Resource.h>
#include <string>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class VertexProgram : public Resource {
                public:
                    VertexProgram(const std::string& code);
                    ~VertexProgram();
            };
        }
    }
}
