#include <Veritas/GPU/Textures/ImageBinding.h>

#include <Veritas/GPU/Definitions.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

ImageBinding::ImageBinding(uint32 location, const Texture &texture, PERMISSION ipermission)
    : BindingPoint(
          [location, &texture, ipermission] {
            uint32 opermission = 0;
            if (ipermission&WRITE && ipermission&READ)
                opermission = GL_READ_WRITE;
            else if (ipermission&WRITE)
                opermission = GL_WRITE_ONLY;
            else if (ipermission&READ)
                opermission = GL_READ_ONLY;

            glActiveTexture(GL_TEXTURE0 + location);
            glBindTexture(texture.getTarget(), texture.getID());
            glBindImageTexture(location, texture.getID(), 0, false, 0, opermission, texture.getInternalFormat());
          },
          [&texture, location] {
            glActiveTexture(GL_TEXTURE0 + location);
            glBindTexture(texture.getTarget(), 0);
          })
{}
