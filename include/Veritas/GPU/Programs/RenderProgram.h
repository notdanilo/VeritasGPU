#pragma once

#include "Program.h"
#include "FragmentProgram.h"
#include "VertexProgram.h"

#include "../BindingPoint.h"

namespace Veritas {
    namespace GPU {
        namespace Programs {
            class RenderProgram : public Resource {
                public:
                    RenderProgram(const VertexProgram& vp, const FragmentProgram& fp);
                    ~RenderProgram();

                    typedef std::initializer_list<BindingPoint> Bindings;
                    void points(uint32 ammount, Bindings bindings = {});
            private:
                    const VertexProgram& vp;
                    const FragmentProgram& fp;
            };
        }
    }
}

/*

#include "Program.h"
#include "../Shaders/Shaders.h"
#include "../Buffers/Buffers.h"
#include "../Textures/Textures.h"

namespace Veritas {
    namespace Graphics {
        namespace API {
            class RenderProgram : public Program {
                public:
                    class VertexArrayObject;

                    RenderProgram(Shaders::VertexShader* vs, Shaders::FragmentShader* fs);
                    RenderProgram(Shaders::VertexShader* vs, Shaders::GeometryShader* gs, Shaders::FragmentShader* fs);

                    Shaders::VertexShader* getVertexShader() const;
                    Shaders::GeometryShader* getGeometryShader() const;
                    Shaders::FragmentShader* getFragmentShader() const;

                    void sampler(int32 uniform, Samplers::Sampler *sampler);
                    void sampler(const char* uniform, Samplers::Sampler *sampler);

                    void render(Buffers::FrameBuffer *fb, uint32 primitive, VertexArrayObject *vao);
                    enum PRIMITIVES { POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON };

                    void setDepthTesting(bool b);
                    bool isDepthTesting() const;

                    void setFaceCulling(bool b);
                    bool isFaceCulling() const;

                    void setColorBlending(bool b);
                    bool isColorBlending() const;

                    void setColorRendering(bool b);
                    bool isColorRendering() const;

                    void setDepthRendering(bool b);
                    bool isDepthRendering() const;

                    void setStencilRendering(bool b);
                    bool isStencilRendering() const;

                private:
                    bool depthtesting, faceculling, colorblending;
                    bool colorrendering, depthrendering, stencilrendering;

                    Shaders::VertexShader* vs;
                    Shaders::GeometryShader *gs;
                    Shaders::FragmentShader *fs;

                    void CRenderProgram(Shaders::VertexShader* vs, Shaders::GeometryShader* gs, Shaders::FragmentShader* fs);
                    void startRendering(Buffers::FrameBuffer *fb);

                    uint32 quantity;

                    friend class Context;
                    class GPU {
                        public:
                            GPU();
                            void setDepthRendering(bool b);
                            void setColorRendering(bool b);
                            void setStencilRendering(bool b);
                            void setFaceCulling(bool b);
                            void setColorBlending(bool b);
                            void setDepthTesting(bool b);
                        private:
                            bool depthtesting, faceculling, colorblending, colorrendering, depthrendering, stencilrendering;
                    };
            };
        }
    }
}

#include "RenderProgram.VertexArrayObject.h"
*/
