#pragma once

#include <Veritas/Definitions/Definitions.h>

#ifdef PLATFORM_WINDOWS
    #define GPU_GL45 "OpenGL 4.5"
    #define GPU_BACKEND GPU_GL45
    #include <Veritas/OpenGL/OpenGL45.h>
#elif defined(PLATFORM_LINUX)
    #define GPU_GLES32 "OpenGL ES 3.2"
    #define GPU_BACKEND GPU_GLES32
    #include <GLES3/gl32.h>
#endif
