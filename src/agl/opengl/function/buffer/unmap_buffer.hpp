#pragma once

#include "agl/opengl/qualifier/buffer.hpp"

namespace agl {

inline
GLboolean unmap_buffer(Buffer b) {
    return glUnmapNamedBuffer(b);
}

inline
GLboolean unmap(Buffer b) {
    return glUnmapNamedBuffer(b);
}

}
