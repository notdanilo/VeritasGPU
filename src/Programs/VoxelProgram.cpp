#include <Veritas/GPU/Programs/VoxelProgram.h>

using namespace Veritas;
using namespace GPU;
using namespace Programs;
using namespace Textures;

#define GLSL(...) #__VA_ARGS__

VoxelProgram::VoxelProgram() : Program(0) {
    fp = new FragmentProgram(GLSL(
        precision highp float;

        layout(location = 0) uniform mat4 toWorld;
        layout(location = 3) uniform mat4 toCamera;
        layout(location = 10) uniform float time;

        float sphere(vec3 o, float r) { return length(o) - r; }
        float box(vec3 p, vec3 b) {
            vec3 d = abs(p) - b;
            return min(max(d.x,max(d.y,d.z)),0.0) + length(max(d,0.0));
        }

        float df(vec3 o) {
            o = (toWorld * vec4(o, 1.0)).xyz;
            float d = box(o, vec3(1.0));
            for (int i = 0; i < 2; i++) {
                o.y += sin(o.x * 50.0) * 0.01;
                o.z += cos(o.y * 50.0) * 0.01;
                o.x += sin(o.z * 50.0) * 0.01;
            }
            d = mix(d, sphere(o, 1.0), cos(time) * 0.5 + 0.5);
            return d;
        }

        float EPS = 0.00001;
        vec3 getNormal(vec3 o) {
            vec3 normal;
            vec3 EPSX = vec3(EPS, 0.0, 0.0);
            vec3 EPSY = vec3(0.0, EPS, 0.0);
            vec3 EPSZ = vec3(0.0, 0.0, EPS);
            normal.x = df(o + EPSX) - df(o - EPSX);
            normal.y = df(o + EPSY) - df(o - EPSY);
            normal.z = df(o + EPSZ) - df(o - EPSZ);
            return normalize(normal);
        }

        layout(location = 0) out vec4 color;

        layout(location = 300) uniform vec2 resolution;

        void main(void) {
            vec2 uv = gl_FragCoord.xy / resolution;
            vec2 p = (2.0 * gl_FragCoord.xy - resolution) / resolution.y;

            vec3 origin = (toCamera * vec4(0.0, 0.0, 0.0, 1.0)).xyz;
            vec3 direction = normalize(vec3(p, -1.0));

            color = vec4(direction, 1.0);

            float t = 0.0;
            for (int i = 0; i < 50; i++) {
                vec3 o = origin + direction * t;
                float d = df(o);
                if (d < EPS) {
                     float n = 1.0;
                     float f = 1000.0;
                     float ze = origin.z - o.z;
                     gl_FragDepth = (-(f + n)/(f - n) * ze - (2.0*f*n)/(f - n)) / ze;
                     gl_FragDepth = (gl_FragDepth + 1.0)/2.0 + 1.0; // why

                     if (gl_FragDepth < 0.0) discard;

                     vec3 normal = getNormal(o);
                     color = vec4(reflect(direction, normal), 1.0);
                     break;
                }
                t += d + 0.001;
            }
        }
        ));

    vp = new VertexProgram(GLSL(
        void main(void) {
           gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
           gl_PointSize = 1000.0;
        }
    ));

    rp = new RasterProgram(*vp, *fp);
}

VoxelProgram::~VoxelProgram() {
    delete vp;
    delete fp;
    delete rp;
}

void VoxelProgram::render(FrameBuffer& fb, const vec3 &position, const vec3 &direction, Bindings ibindings) {
    Bindings bindings = ibindings;
    Texture2D* color = fb.getColorBuffer();
    bindings.push_back(UniformBinding(300, *fp, vec2(color->getWidth(), color->getHeight())));
    bindings.push_back(UniformBinding(10, *fp, position.x));
    //bindings.push_back(UniformBinding(300, *fp, position));
    //bindings.push_back(UniformBinding(301, *fp, direction));
    rp->points(fb, 1, true, bindings );
}

FragmentProgram& VoxelProgram::getFragmentProgram() { return *fp; }
