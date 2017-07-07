#pragma once

#include <Veritas/GPU/BindingPoint.h>
#include <list>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class Program : public Resource {
                public:
                    typedef std::list<BindingPoint> Bindings;
                protected:
                    Program(uint32 id);
            };
        }
    }
}
