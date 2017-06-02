#include <Veritas/GPU/BindingPoint.h>

using namespace Veritas;
using namespace GPU;

BindingPoint::BindingPoint(const Resource &resource, uint32 location) : resource(resource), location(location) {}

const Resource& BindingPoint::getResource() const { return resource; }
uint32 BindingPoint::getLocation() const { return location; }
