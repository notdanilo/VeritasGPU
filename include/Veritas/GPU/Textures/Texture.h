#pragma once

#include "../Resource.h"

namespace Veritas {
    namespace GPU {
        namespace Textures {
            class Texture : public Resource {
                public:
                    enum ELEMENTS { DEPTH, /*UV, RGB,*/ RGBA };
                    enum TYPE { FLOAT32 /*, UINT8 */ };
                    enum SPACE { ONE_DIMENSION, TWO_DIMENSION, THREE_DIMENSION, CUBE_PROJECTION };

                    ELEMENTS getElements() const;
                    TYPE getType() const;

                    SPACE getSpace() const;

                    ~Texture();
                protected:
                    Texture(ELEMENTS elements, TYPE type, SPACE space);
                private:
                    ELEMENTS elements;
                    TYPE type;
                    SPACE space;
            };
        }
    }
}
