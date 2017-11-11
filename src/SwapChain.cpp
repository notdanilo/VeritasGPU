#include <Veritas/GPU/SwapChain.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

SwapChain::SwapChain(uint32 width, uint32 height, uint8 ammount)
    : chain(ammount)
    , offset(0)
{
    for (uint32 i = 0; i < chain.size(); i++) {
        FrameBuffer* fb = new FrameBuffer(width, height);
        Texture2D* color = new Texture2D(width, height, Texture::RGBA, Texture::UINT8);
        Texture2D* depth = new Texture2D(width, height, Texture::DEPTH, Texture::UINT16);
        fb->setColorBuffer(*color);
        fb->setDepthBuffer(*depth);
        chain[i] = fb;
    }
}

SwapChain::~SwapChain() {
    for (uint32 i = 0; i < chain.size(); i++) {
        FrameBuffer *fb = chain[i];
        delete fb->getColorBuffer();
        delete fb->getDepthBuffer();
        delete fb->getStencilBuffer();
        delete fb;
    }
}

void SwapChain::advance() { offset++; }
FrameBuffer& SwapChain::get(const uint32 index) { return *chain[(index + offset) % chain.size()]; }
