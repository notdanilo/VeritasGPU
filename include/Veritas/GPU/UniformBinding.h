#pragma once

#include <Veritas/GPU/BindingPoint.h>

namespace Veritas {
    namespace GPU {
        class UniformBinding : public BindingPoint {
            public:
                UniformBinding(uint32 location, const Resource& program, float32 value);
                UniformBinding(uint32 location, const Resource& program, const vec2& value);
                UniformBinding(uint32 location, const Resource& program, const vec3& value);
                UniformBinding(uint32 location, const Resource& program, const vec4& value);
                UniformBinding(uint32 location, const Resource& program, const mat2& value);
                UniformBinding(uint32 location, const Resource& program, const mat3& value);
                UniformBinding(uint32 location, const Resource& program, const mat4& value);
                UniformBinding(uint32 location, const Resource& program, const int32 value);
                UniformBinding(uint32 location, const Resource& program, const ivec2& value);
                UniformBinding(uint32 location, const Resource& program, const ivec3& value);
                UniformBinding(uint32 location, const Resource& program, const ivec4& value);
                UniformBinding(uint32 location, const Resource& program, const uint32 value);
                UniformBinding(uint32 location, const Resource& program, const uvec2& value);
                UniformBinding(uint32 location, const Resource& program, const uvec3& value);
                UniformBinding(uint32 location, const Resource& program, const uvec4& value);
        };
    }
}
