#include <Veritas/GPU/BindingPoint.h>

using namespace Veritas;
using namespace GPU;

BindingPoint::BindingPoint(std::function<void ()> bind, std::function<void ()> unbind)
    : fbind(bind)
    , funbind(unbind)
{}

void BindingPoint::bind() const { fbind(); }
void BindingPoint::unbind() const { funbind(); }
