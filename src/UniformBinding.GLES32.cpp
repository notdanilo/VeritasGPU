#include <Veritas/GPU/UniformBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

UniformBinding::UniformBinding(uint32 location, const Resource& program, float32 value)
    : BindingPoint(
          [&program, location, value] {
            glProgramUniform1f(program.getID(), location, value);
          },
          [&program, location] {
            glProgramUniform1f(program.getID(), location, 0.0f);
          })
{}

UniformBinding::UniformBinding(uint32 location, const Resource &program, int32 value)
    : BindingPoint(
        [&program, value, location] {
            glProgramUniform1i(program.getID(), location, value);
        },
        [&program, location] {
            glProgramUniform1i(program.getID(), location, 0);
        })
{}
