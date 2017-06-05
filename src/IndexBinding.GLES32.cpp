#include <Veritas/GPU/IndexBinding.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;

IndexBinding::IndexBinding(const Buffer& buffer, TYPE type)
    : BindingPoint([&buffer] {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.getID());
      },
      [] {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //is generating glGetError()
      }), type(type)
{}

IndexBinding::TYPE IndexBinding::getType() const { return type; }
