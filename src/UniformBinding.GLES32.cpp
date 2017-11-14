#include <Veritas/GPU/UniformBinding.h>

#include <functional>

#include <Veritas/GPU/Definitions.h>

using namespace Veritas;
using namespace GPU;

UniformBinding::UniformBinding(uint32 location, const Resource& program, float32 value)
    : BindingPoint([&program, location, value] {
        glProgramUniform1fv(program.getID(), location, 1, &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const vec2& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform2fv(program.getID(), location, 1, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const vec3& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform3fv(program.getID(), location, 1, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const vec4& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform4fv(program.getID(), location, 1, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const mat2& value)
    : BindingPoint([&program, location, value] {
        glProgramUniformMatrix2fv(program.getID(), location, 1, false, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const mat3& value)
    : BindingPoint([&program, location, value] {
        glProgramUniformMatrix3fv(program.getID(), location, 1, false, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const mat4& value)
    : BindingPoint([&program, location, value] {
        glProgramUniformMatrix4fv(program.getID(), location, 1, false, (float32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, int32 value)
    : BindingPoint([&program, location, value] {
        glProgramUniform1iv(program.getID(), location, 1, (int32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const ivec2& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform2iv(program.getID(), location, 1, (int32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const ivec3& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform3iv(program.getID(), location, 1, (int32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const ivec4& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform4iv(program.getID(), location, 1, (int32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, uint32 value)
    : BindingPoint([&program, location, value] {
        glProgramUniform1uiv(program.getID(), location, 1, (uint32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const uvec2& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform2uiv(program.getID(), location, 1, (uint32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const uvec3& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform3uiv(program.getID(), location, 1, (uint32*) &value);
      }, [] {})
{}

UniformBinding::UniformBinding(uint32 location, const Resource& program, const uvec4& value)
    : BindingPoint([&program, location, value] {
        glProgramUniform4uiv(program.getID(), location, 1, (uint32*) &value);
      }, [] {})
{}
