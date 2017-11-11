#pragma once

#include <Veritas/GPU/FrameBuffer.h>
#include <vector>

namespace Veritas {
    namespace GPU {
        class SwapChain {
            public:
                SwapChain(uint32 width, uint32 height, uint8 ammount);
                ~SwapChain();

                void advance();

                uint32 getWidth() const;
                uint32 getHeight() const;
                uint8 getAmmount() const;

                FrameBuffer& get(const uint32 index);
                const FrameBuffer& get(const uint32 index) const;

            private:
                uint32 offset;
                std::vector<FrameBuffer*> chain;
        };
    }
}
