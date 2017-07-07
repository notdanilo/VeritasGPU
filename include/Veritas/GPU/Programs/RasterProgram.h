#pragma once

#include "Program.h"
#include "FragmentProgram.h"
#include "VertexProgram.h"

#include "../BindingPoint.h"
#include "../IndexBinding.h"
#include "../FrameBuffer.h"

#include <list>

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class RasterProgram : public Program {
                public:
                    RasterProgram(const VertexProgram& vp, const FragmentProgram& fp);
                    ~RasterProgram();

                    void points(FrameBuffer& fb, uint32 npoints, bool depthTesting, const Bindings& bindings = {});
                    void lines(FrameBuffer& fb, uint32 nlines, bool depthTesting, const Bindings& bindings = {});
                    void lines(FrameBuffer& fb, uint32 nlines, bool depthTesting, const IndexBinding& indices, const Bindings& bindings = {});
                    void triangles(FrameBuffer& fb, uint32 ntriangles, bool depthTesting, bool faceCulling, const IndexBinding& indices, const Bindings &bindings = {});
            private:
                    const VertexProgram& vp;
                    const FragmentProgram& fp;
            };
        }
    }
}
