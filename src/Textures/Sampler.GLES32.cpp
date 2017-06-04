#include <Veritas/GPU/Textures/Sampler.h>

#include <GLES3/gl32.h>

using namespace Veritas;
using namespace GPU;
using namespace Textures;

uint32 createSampler() {
    uint32 sampler;
    glGenSamplers(1, &sampler);
    return sampler;
}

Sampler::Sampler(FILTERING in, FILTERING out, WRAPPING x, WRAPPING y, WRAPPING z) : Resource(createSampler()) {
    setWrapping(x, y, z);
    setFiltering(in, out);
}

Sampler::~Sampler() {
    glDeleteSamplers(1, &getID());
}

void Sampler::setWrapping(WRAPPING x, WRAPPING y, WRAPPING z) {
    uint32 iparams[3] = { x, y, z };
    uint32 oparams[3];
    for (int i = 0; i < 3; i++)
        switch (iparams[i]) {
            case REPEAT: oparams[i] = GL_REPEAT; break;
            case MIRRORED_REPEAT: oparams[i] = GL_MIRRORED_REPEAT; break;
            case CLAMP_TO_EDGE: oparams[i] = GL_CLAMP_TO_EDGE; break;
            case CLAMP_TO_BORDER: oparams[i] = GL_CLAMP_TO_BORDER; break;
        }

    glSamplerParameteri(getID(), GL_TEXTURE_WRAP_S, oparams[0]);
    glSamplerParameteri(getID(), GL_TEXTURE_WRAP_T, oparams[1]);
    glSamplerParameteri(getID(), GL_TEXTURE_WRAP_R, oparams[2]);
}

void Sampler::setFiltering(FILTERING in, FILTERING out) {
    uint32 iparams[2] { in, out };
    uint32 oparams[2];
    for (int i = 0; i < 2; i++)
        switch (iparams[i]) {
            case NEAREST: oparams[i] = GL_NEAREST; break;
            case LINEAR: oparams[i] = GL_LINEAR; break;
            case NEAREST_MIPMAP_NEAREST: oparams[i] = GL_NEAREST_MIPMAP_NEAREST; break;
            case LINEAR_MIPMAP_NEAREST: oparams[i] = GL_LINEAR_MIPMAP_NEAREST; break;
            case NEAREST_MIPMAP_LINEAR: oparams[i] = GL_NEAREST_MIPMAP_LINEAR; break;
            case LINEAR_MIPMAP_LINEAR: oparams[i] = GL_LINEAR_MIPMAP_LINEAR; break;
        }
    glSamplerParameteri(getID(), GL_TEXTURE_MAG_FILTER, oparams[0]);
    glSamplerParameteri(getID(), GL_TEXTURE_MIN_FILTER, oparams[1]);
}
