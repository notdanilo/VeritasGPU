#include <Veritas/GPU/Textures/SamplerBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

SamplerBinding::SamplerBinding(uint32 location, const Sampler &sampler, const Resource& program, const Texture &texture, uint32 unit)
    : BindingPoint(
          [&, unit, location] {
            uint32 target = 0;
            switch (texture.getSpace()) {
                case Texture::TWO_DIMENSION: target = GL_TEXTURE_2D; break;
                case Texture::THREE_DIMENSION: target = GL_TEXTURE_3D; break;
                case Texture::CUBE_PROJECTION: target = GL_TEXTURE_CUBE_MAP; break;
            }

            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(target, texture.getID());
            glBindSampler(unit, sampler.getID());
            glProgramUniform1i(program.getID(), location, unit);
          },
          [&texture, unit] {
            uint32 target = 0;
            switch (texture.getSpace()) {
                case Texture::TWO_DIMENSION: target = GL_TEXTURE_2D; break;
                case Texture::THREE_DIMENSION: target = GL_TEXTURE_3D; break;
                case Texture::CUBE_PROJECTION: target = GL_TEXTURE_CUBE_MAP; break;
            }

            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(target, 0);
            glBindSampler(unit, 0);
          })
    , uniform(location, program, (int32) unit)
{}
