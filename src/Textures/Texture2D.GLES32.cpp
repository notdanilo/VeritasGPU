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
    uint32 dataFormat = 0;
    uint32 dataType = 0;
    uint32 internalFormat = 0;

    if (elements == DEPTH) {
        if (type == FLOAT32) {
            internalFormat = GL_DEPTH_COMPONENT32F;
            dataFormat = GL_DEPTH_COMPONENT;
            dataType = GL_FLOAT;
        }
    } else if (elements == RGBA) {
        if (type == FLOAT32) {
            internalFormat = GL_RGBA32F;
            dataFormat = GL_RGBA;
            dataType = GL_FLOAT;
        }
    }


    glBindTexture(GL_TEXTURE_2D, getID());
    glTexStorage2D(GL_TEXTURE_2D, 1, internalFormat, width, height);
    if (data) glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, dataFormat, dataType, data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

uint32 Texture2D::getWidth() const { return width; }
uint32 Texture2D::getHeight() const { return height; }
