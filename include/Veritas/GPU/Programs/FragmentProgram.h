#pragma once

#include <Veritas/GPU/Resource.h>
#include <string>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class FragmentProgram : public Resource {
                public:
                    FragmentProgram(const std::string& code);
                    ~FragmentProgram();
                private:
                    friend class RenderProgram;
            };
        }
    }
}
