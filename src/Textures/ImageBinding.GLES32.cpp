#include <Veritas/GPU/Textures/ImageBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

ImageBinding::ImageBinding(uint32 location, const Texture &texture, PERMISSION ipermission)
    : BindingPoint(
          [location, &texture, ipermission] {
            uint32 format = 0;
            if (texture.getElements() == Texture::RGBA) {
                if (texture.getType() == Texture::FLOAT32)
                    format = GL_RGBA32F;
            } else if (texture.getElements() == Texture::DEPTH) {
                if (texture.getType() == Texture::FLOAT32)
                    format = GL_DEPTH_COMPONENT32F;
            }

            uint32 opermission = 0;
            if (ipermission&WRITE && ipermission&READ)
                opermission = GL_READ_WRITE;
            else if (ipermission&WRITE)
                opermission = GL_WRITE_ONLY;
            else if (ipermission&READ)
                opermission = GL_READ_ONLY;

            uint32 target = 0;
            switch (texture.getSpace()) {
                case Texture::TWO_DIMENSION: target = GL_TEXTURE_2D; break;
                case Texture::THREE_DIMENSION: target = GL_TEXTURE_3D; break;
                case Texture::CUBE_PROJECTION: target = GL_TEXTURE_CUBE_MAP; break;
            }

            glActiveTexture(GL_TEXTURE0 + location);
            glBindTexture(target, texture.getID());
            glBindImageTexture(location, texture.getID(), 0, false, 0, opermission, format);
          },
          [&texture, location] {
            uint32 target = 0;
            switch (texture.getSpace()) {
                case Texture::TWO_DIMENSION: target = GL_TEXTURE_2D; break;
                case Texture::THREE_DIMENSION: target = GL_TEXTURE_3D; break;
                case Texture::CUBE_PROJECTION: target = GL_TEXTURE_CUBE_MAP; break;
            }

            glActiveTexture(GL_TEXTURE0 + location);
            glBindTexture(target, 0);
          })
{}
