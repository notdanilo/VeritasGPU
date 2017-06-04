#include <Veritas/GPU/Buffer.h>

#include <GLES3/gl32.h>
#include <cstring>

using namespace Veritas::GPU;

uint32 glCreateBuffer() {
    uint32 buffer;
    glGenBuffers(1, &buffer);
    return buffer;
}

Buffer::Buffer(uint32 size) : Buffer(size, 0) {}
Buffer::Buffer(uint32 size, void *data) : Resource(glCreateBuffer()) {
    glBindBuffer(GL_ARRAY_BUFFER, getID());
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &getID());
}

uint32 Buffer::getSize() const {
    int32 size;
    glBindBuffer(GL_ARRAY_BUFFER, getID());
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    return size;
}

void Buffer::write(void *data, uint32 length) { write(data, 0, length); }
void Buffer::write(void *cpumem, uint32 offset, uint32 length) {
    glBindBuffer(GL_ARRAY_BUFFER, getID());

    void *gpumem = glMapBufferRange(GL_ARRAY_BUFFER, offset, length, GL_MAP_WRITE_BIT);
    memcpy(gpumem, cpumem, length);
    glUnmapBuffer(GL_ARRAY_BUFFER);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::read(void *data, uint32 length) { read(data, 0, length); }
void Buffer::read(void *cpumem, uint32 offset, uint32 length) {
    glBindBuffer(GL_ARRAY_BUFFER, getID());

    void *gpumem = glMapBufferRange(GL_ARRAY_BUFFER, offset, length, GL_MAP_READ_BIT);
    memcpy(cpumem, gpumem, length);
    glUnmapBuffer(GL_ARRAY_BUFFER);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
