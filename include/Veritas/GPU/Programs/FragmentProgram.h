#pragma once

#include <Veritas/Data/String.h>
#include "../Resource.h"

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class FragmentProgram : public Resource {
                public:
                    FragmentProgram(const Data::String& code);
                    ~FragmentProgram();
                private:
                    friend class RenderProgram;
            };
        }
    }
}
