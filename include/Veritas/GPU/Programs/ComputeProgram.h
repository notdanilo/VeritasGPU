#pragma once

#include <Veritas/GPU/Programs/Program.h>
#include <Veritas/Math/vec3.h>
#include <Veritas/GPU/Buffer.h>
#include <Veritas/GPU/BindingPoint.h>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            using Math::uvec2;
            using Math::uvec3;
            class ComputeProgram : public Program {
                public:
                    ComputeProgram(const std::string& code);
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
}
