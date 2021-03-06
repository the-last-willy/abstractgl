#pragma once

#include "glad/glad.h"

namespace agl {

enum class Capability : GLenum {
    blend = GL_BLEND,
    cull_face = GL_CULL_FACE,
    debug_output = GL_DEBUG_OUTPUT,
    depth_test = GL_DEPTH_TEST,
    line_smooth = GL_LINE_SMOOTH,
    program_point_size =  GL_PROGRAM_POINT_SIZE,
    texture_cube_map_seamless = GL_TEXTURE_CUBE_MAP_SEAMLESS,
};

inline
void enable(Capability c) {
    glEnable(static_cast<GLenum>(c));
}

inline
void disable(Capability c) {
    glDisable(static_cast<GLenum>(c));
}

}
