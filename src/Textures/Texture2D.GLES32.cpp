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
    glBindTexture(GL_TEXTURE_2D, getID());
    glTexStorage2D(GL_TEXTURE_2D, 1, getInternalFormat(), width, height);
    if (data) glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, getDataFormat(), getDataType(), data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

uint32 Texture2D::getWidth() const { return width; }
uint32 Texture2D::getHeight() const { return height; }
