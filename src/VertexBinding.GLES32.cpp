#include <Veritas/GPU/VertexBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

VertexBinding::VertexBinding(uint32 location, const Buffer &buffer, uint32 elementSize)
    : BindingPoint(
          [&buffer, location, elementSize] {
            glBindBuffer(GL_ARRAY_BUFFER, buffer.getID());
            glVertexAttribPointer(location, elementSize, GL_FLOAT, false, 0, 0);
            glEnableVertexAttribArray(location);
          },
          [] {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
          })
{}
