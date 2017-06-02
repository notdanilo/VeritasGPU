#ifndef SILEXARS_GRAPHICS_API_RENDERPROGRAM_VERTEXARRAYOBJECT_H
#define SILEXARS_GRAPHICS_API_RENDERPROGRAM_VERTEXARRAYOBJECT_H

#include "RenderProgram.h"

// Reminder: GL_ELEMENTS_ARRAY_BUFFER isn't stored on some implementations of VAO (GLES extension guarantees it)

namespace Veritas {
    namespace Graphics {
        namespace API {
            class RenderProgram::VertexArrayObject {
                public:
                    VertexArrayObject();
                    ~VertexArrayObject();

                    void setVertexBuffer(uint32 location, Buffers::VertexBuffer *vb);
                    Buffers::VertexBuffer* getVertexBuffer(uint32 location) const;

                    void setIndexBuffer(Buffers::IndexBuffer *ib);
                    Buffers::IndexBuffer* getIndexBuffer() const;                    
                private:
                    friend class RenderProgram;

                    uint32 nlocations;
                    uint32* locations;
                    Buffers::VertexBuffer **vbs;
                    Buffers::IndexBuffer *ib;

                    void use();
            };
        }
    }
}

#endif // RENDERPROGRAM_VERTEXARRAYOBJECT_H
