/*
//! Are these matters still valid?
//! LocationBindings happens on ComputeProgram::compute and RenderProgram::render for consistency. It can be optimized.
//! Each program must maintain its LocationBindings always consistent.
//! Program::use must recover its LocationBindings.
//! The LocationBindings of a Program can be changed between Program::use and render/compute.
//! Checking for consistency on render/compute can be CPU exhaustive. (Current implementation)
//! The current implementation doesn't check if render/compute's specific OpenGL calls (glBindImageTexture, glVertexAttribPointer, uniform) are already consistent.

//!Dirty! Remove LocationBindings, it is no longer used for attributes
#pragma once

#include <Veritas/Definitions/Definitions.h>
#include "../Textures/Texture.h"
#include "../Buffers/Buffers.h"
#include <map>

namespace Veritas {
    namespace Graphics {
        namespace API {
            class Program {
                public:
                    ~Program();

                    bool isValid() const;
                    const char* getMessage() const;

                    int32 getUniformBufferLocation(const char *uniformBuffer) const;

                    void uniformBuffer(int32 location, Buffers::UniformBuffer* ubo);
                    void uniformBuffer(const char* name, Buffers::UniformBuffer* ubo);

                    Buffers::UniformBuffer* getLocalUniformBuffer() const;
                protected:
                    Program();

                    uint32 id;
                    void use();
                    void link();

                    class LocationBinding {
                        public:
                            LocationBinding(int32 location, void *object, uint32 permission);
                            int32 location;
                            void *object;
                            uint32 permission;

                            enum PERMISSIONS { READ_ONLY, WRITE_ONLY, READ_WRITE };
                    };
                    class LocationBindings {
                        public:
                            LocationBindings();
                            ~LocationBindings();
                            uint32 set(int32 location, void *object, uint32 permission = LocationBinding::READ_ONLY);

                            int32 nbindings;
                            LocationBinding *bindings;
                    };

                    LocationBindings samplers, ubos;
                private:
                    friend class Buffers::UniformBuffer;

                    bool isvalid;
                    char* message;

                    Buffers::UniformBuffer *localubo;
            };
        }
    }
}
*/
