#include <Veritas/GPU/Textures/Texture2D.h>
#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

Texture2D::Texture2D(uint32 width, uint32 height, ELEMENTS elements, TYPE type, const void *data)
    : Texture(elements, type, TWO_DIMENSION)
    , width(width)
    , height(height)
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

    glBindTexture(GL_TEXTURE_2D, getID());
    glTexStorage2D(GL_TEXTURE_2D, 1, oformat, width, height);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, oelements, otype, data);
    glBindTexture(GL_TEXTURE_2D, 0);
}
