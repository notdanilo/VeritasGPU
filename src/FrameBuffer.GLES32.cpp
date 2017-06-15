#include <Veritas/GPU/FrameBuffer.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

uint32 createFrameBuffer() {
    uint32 framebuffer;
    glGenFramebuffers(1, &framebuffer);
    return framebuffer;
}

FrameBuffer::FrameBuffer(uint32 id, uint32 width, uint32 height)
    : Resource(id)
    , width(width)
    , height(height)
    , colorBuffer(0)
    , depthBuffer(0)
    , stencilBuffer(0)
{}
FrameBuffer::FrameBuffer(uint32 width, uint32 height) : FrameBuffer(createFrameBuffer(), width, height) {}
FrameBuffer::~FrameBuffer() {
    if (getID()) glDeleteBuffers(1, &getID());
}

uint32 FrameBuffer::getWidth() const { return width; }
uint32 FrameBuffer::getHeight() const { return height; }

void FrameBuffer::setColorBuffer(Texture2D& texture) {
    colorBuffer = &texture;
    glBindFramebuffer(GL_FRAMEBUFFER, getID());
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.getID(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void FrameBuffer::setDepthBuffer(Texture2D& texture) {
    depthBuffer = &texture;
    glBindFramebuffer(GL_FRAMEBUFFER, getID());
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture.getID(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void FrameBuffer::setStencilBuffer(Texture2D &texture) {
    stencilBuffer = &texture;
    glBindFramebuffer(GL_FRAMEBUFFER, getID());
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture.getID(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Texture2D* FrameBuffer::getColorBuffer() const { return colorBuffer; }
Texture2D* FrameBuffer::getDepthBuffer() const { return depthBuffer; }
Texture2D* FrameBuffer::getStencilBuffer() const { return stencilBuffer; }
