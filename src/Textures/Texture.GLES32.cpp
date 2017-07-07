#include <Veritas/GPU/Textures/Texture.h>

#include <GLES3/gl32.h>

#include <cassert>

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
{
    assert(!(elements == DEPTH && type == UINT8));
    assert(!(elements == DEPTH && type == UINT32));
}
Texture::~Texture() {
    glDeleteTextures(1, &getID());
}

Texture::ELEMENTS Texture::getElements() const { return elements; }
Texture::TYPE Texture::getType() const { return type; }
Texture::SPACE Texture::getSpace() const { return space; }

uint32 Texture::getDataFormat() const {
    switch (elements) {
        case DEPTH: return GL_DEPTH_COMPONENT;
        case RGB: return GL_RGB;
        case RGBA: return GL_RGBA;
    }
}

uint32 Texture::getDataType() const {
    switch (type) {
        case FLOAT32: return GL_FLOAT;
//        case INT8: return GL_BYTE;
//        case INT16: return GL_SHORT;
//        case INT32: return GL_INT;
        case UINT8: return GL_UNSIGNED_BYTE;
        case UINT16: return GL_UNSIGNED_SHORT;
        case UINT32: return GL_UNSIGNED_INT;
    }
}

#include <map>
uint32 Texture::getInternalFormat() const {
    static std::map<std::pair<uint32, uint32>, uint32> map = {
        { { DEPTH, FLOAT32 }, GL_DEPTH_COMPONENT32F },
        { { DEPTH, UINT16 }, GL_DEPTH_COMPONENT16 },
        { { RGB, FLOAT32 }, GL_RGB32F },
        { { RGB, UINT8 }, GL_RGB8 },
        { { RGB, UINT16 }, GL_RGB16UI },
        { { RGB, UINT32 }, GL_RGB32UI },
        { { RGBA, FLOAT32 }, GL_RGBA32F },
        { { RGBA, UINT8 }, GL_RGBA8 },
        { { RGBA, UINT16 }, GL_RGBA16UI },
        { { RGBA, UINT32 }, GL_RGBA32UI }
    };
    return map[{ elements, type }];
}

uint32 Texture::getTarget() const {
    switch (space) {
        case ONE_DIMENSION: return GL_TEXTURE_BUFFER;
        case TWO_DIMENSION: return GL_TEXTURE_2D;
        case THREE_DIMENSION: return GL_TEXTURE_3D;
        case CUBE_PROJECTION: return GL_TEXTURE_CUBE_MAP;
    }
}
