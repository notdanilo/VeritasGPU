#include <Veritas/GPU/Textures/Texture3D.h>
#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

Texture3D::Texture3D(uint32 width, uint32 height, uint32 depth, ELEMENTS elements, TYPE type, const void *data)
    : Texture(elements, type, THREE_DIMENSION)
    , width(width)
    , height(height)
    , depth(depth)
{
    uint32 oelements = 0;
    uint32 otype = 0;
    uint32 oformat = 0;
    if (elements == RGBA) {
        oelements = GL_RGBA;
        if (type == FLOAT32) {
            otype = GL_FLOAT;
            oformat = GL_RGBA32F;
        }
    }

    glBindTexture(GL_TEXTURE_3D, getID());
    glTexStorage3D(GL_TEXTURE_3D, 1, oformat, width, height, depth);
    glTexSubImage3D(GL_TEXTURE_3D, 0, 0, 0, 0, width, height, depth, oelements, otype, data);
    glBindTexture(GL_TEXTURE_3D, 0);
}
