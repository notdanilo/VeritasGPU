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

/*
#pragma once

#include "Program.h"
#include "../Shaders/Shaders.h"
#include "../Buffers/Buffers.h"
#include "../Textures/Textures.h"

namespace Veritas {
    namespace Graphics {
        namespace API {
            class ComputeProgram : public Program {
                public:
                    ComputeProgram(Shaders::ComputeShader *cs);

                    Shaders::ComputeShader *getComputeShader() const;

                    void sampler(int32 uniform, Samplers::Sampler *sampler, uint8 permission);
                    void sampler(const char* uniform, Samplers::Sampler *sampler, uint8 permission);
                    enum PERMISSION { READ_ONLY = 0x88B8, WRITE_ONLY = 0x88B9, READ_WRITE = 0x88BA };

                    void compute(uint32 w, uint32 h, uint32 d);
                private:
                    Shaders::ComputeShader *cs;
            };
        }
    }
}
*/
