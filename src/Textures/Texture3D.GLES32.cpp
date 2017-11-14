#include <Veritas/GPU/Textures/Texture3D.h>

#include <Veritas/GPU/Definitions.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

Texture3D::Texture3D(uint32 width, uint32 height, uint32 depth, ELEMENTS elements, TYPE type, const void *data)
    : Texture(elements, type, THREE_DIMENSION)
    , width(width)
    , height(height)
    , depth(depth)
{
    glBindTexture(GL_TEXTURE_3D, getID());
    glTexStorage3D(GL_TEXTURE_3D, 1, getInternalFormat(), width, height, depth);
    if (data) glTexSubImage3D(GL_TEXTURE_3D, 0, 0, 0, 0, width, height, depth, getDataFormat(), getDataType(), data);
    glBindTexture(GL_TEXTURE_3D, 0);
}

uint32 Texture3D::getWidth() const { return width; }
uint32 Texture3D::getHeight() const { return height; }
uint32 Texture3D::getDepth() const { return depth; }
