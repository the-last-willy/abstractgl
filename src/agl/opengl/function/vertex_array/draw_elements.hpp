#pragma once

#include "agl/opengl/qualifier/count.hpp"
#include "agl/opengl/qualifier/draw_mode.hpp"
#include "agl/opengl/qualifier/draw_type.hpp"
#include "agl/opengl/qualifier/offset.hpp"

#include <cstdlib>

namespace agl {

inline
void draw_elements(
    DrawMode dm,
    Count<GLsizei> c,
    DrawType dt,
    Offset<GLintptr> o = Offset<GLintptr>(0))
{
    // TODO: Think some more about Offset<GLintptr>.
    glDrawElements(
        static_cast<GLenum>(dm),
        static_cast<GLsizei>(c),
        static_cast<GLenum>(dt),
        // Get rid of reinterpret_cast somehow.
        reinterpret_cast<const void*>(static_cast<GLintptr>(o)));
}

}
