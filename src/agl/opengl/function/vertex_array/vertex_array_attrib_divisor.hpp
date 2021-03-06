#pragma once

#include "agl/opengl/qualifier/binding_index.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void vertex_array_attrib_binding(
    VertexArray va,
    BindingIndex<GLuint> bi,
    GLuint divisor)
{
    glVertexArrayBindingDivisor(
        static_cast<GLuint>(va),
        static_cast<GLuint>(bi),
        divisor);
}

inline
void attribute_divisor(
    VertexArray va,
    BindingIndex<GLuint> bi,
    GLuint divisor)
{
    vertex_array_attrib_binding(va, bi, divisor);
}

}
