#include <Veritas/GPU/Textures/Texture.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

uint32 createTexture() {
    uint32 texture;
    glGenTextures(1, &texture);
    return texture;
}

Texture::Texture(ELEMENTS elements, TYPE type, SPACE space)
    : Resource(createTexture())
    , elements(elements)
    , type(type)
    , space(space)
{}
Texture::~Texture() {
    glDeleteTextures(1, &getID());
}

Texture::ELEMENTS Texture::getElements() const { return elements; }
Texture::TYPE Texture::getType() const { return type; }
Texture::SPACE Texture::getSpace() const { return space; }
