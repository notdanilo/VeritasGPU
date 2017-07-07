#pragma once

#include "../Resource.h"

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class Texture : public Resource {
                public:
                    enum ELEMENTS { DEPTH, /*UV,*/ RGB, RGBA };
                    enum TYPE { UINT8, UINT16, UINT32, INT16, INT32, FLOAT32 };
                    enum SPACE { ONE_DIMENSION, TWO_DIMENSION, THREE_DIMENSION, CUBE_PROJECTION };

                    ELEMENTS getElements() const;
                    TYPE getType() const;

                    SPACE getSpace() const;

                    ~Texture();
                protected:
                    friend class ImageBinding;
                    friend class SamplerBinding;
                    Texture(ELEMENTS elements, TYPE type, SPACE space);
                    uint32 getDataFormat() const;
                    uint32 getDataType() const;
                    uint32 getInternalFormat() const;
                    uint32 getTarget() const;
                private:
                    ELEMENTS elements;
                    TYPE type;
                    SPACE space;
            };
        }
    }
}
