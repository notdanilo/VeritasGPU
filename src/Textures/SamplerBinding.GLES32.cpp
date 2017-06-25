#include <Veritas/GPU/Textures/SamplerBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

SamplerBinding::SamplerBinding(uint32 location, const Sampler &sampler, const Resource& program, const Texture &texture, uint32 unit)
    : BindingPoint(
          [&, unit, location] {
            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(texture.getTarget(), texture.getID());
            glBindSampler(unit, sampler.getID());
            glProgramUniform1i(program.getID(), location, unit);
          },
          [&texture, unit] {
            glActiveTexture(GL_TEXTURE0 + unit);
            glBindTexture(texture.getTarget(), 0);
            glBindSampler(unit, 0);
          })
    , uniform(location, program, (int32) unit)
{}
