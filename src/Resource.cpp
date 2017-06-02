#include <Veritas/GPU/Resource.h>

using namespace Veritas;
using namespace GPU;

Resource::Resource(uint32 id) : id(id) {}

const uint32 &Resource::getID() const { return id; }
