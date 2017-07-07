#pragma once

#include "RasterProgram.h"
#include "../BindingPoint.h"

#include <list>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class VoxelProgram : public Program {
                public:
                    VoxelProgram();
                    ~VoxelProgram();

                    FragmentProgram& getFragmentProgram();

                    void render(FrameBuffer& fb, const vec3& position, const vec3& direction, Bindings bindings = {});
                private:
                    FragmentProgram *fp;
                    VertexProgram *vp;
                    RasterProgram *rp;
            };
        }
    }
}
