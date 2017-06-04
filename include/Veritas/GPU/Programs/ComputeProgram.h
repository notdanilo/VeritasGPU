#pragma once

#include <Veritas/Data/String.h>
#include <Veritas/Math/vec3.h>
#include "../Buffer.h"
#include "../BindingPoint.h"

namespace Veritas {
    namespace GPU {
        using Math::uvec2;
        using Math::uvec3;
        class ComputeProgram : public Resource {
            public:
                ComputeProgram(const Data::String& code);
                ~ComputeProgram();

                typedef std::initializer_list<BindingPoint> Bindings;
                void compute(const uint32 work, Bindings bindings = {});
                void compute(const uvec2& work, Bindings bindings = {});
                void compute(const uvec3& work, Bindings bindings = {});

                const uvec3& getGroupSize() const;
            private:
                uvec3 groupSize;
        };
    }
}
