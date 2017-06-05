#pragma once

#include "Program.h"
#include "FragmentProgram.h"
#include "VertexProgram.h"

#include "../BindingPoint.h"
#include "../IndexBinding.h"

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class RasterProgram : public Resource {
                public:
                    RasterProgram(const VertexProgram& vp, const FragmentProgram& fp);
                    ~RasterProgram();

                    typedef std::initializer_list<BindingPoint> Bindings;
                    void points(uint32 npoints, bool depthTesting, Bindings bindings = {});
                    void lines(uint32 nlines, bool depthTesting, Bindings bindings = {});
                    void lines(uint32 nlines, bool depthTesting, const IndexBinding& indices, Bindings bindings = {});
                    void triangles(uint32 ntriangles, bool depthTesting, bool faceCulling, const IndexBinding& indices, Bindings bindings = {});
            private:
                    const VertexProgram& vp;
                    const FragmentProgram& fp;
            };
        }
    }
}
