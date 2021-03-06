#pragma once

#include "agl/opengl/name/all.hpp"

#include <span>

namespace agl {

inline
void delete_(VertexArray va) {
    glDeleteVertexArrays(1, &va.id);
}

inline
void delete_vertex_arrays(GLsizei n, VertexArray* vas) {
    glDeleteVertexArrays(
        n,
        reinterpret_cast<GLuint*>(vas));
}

inline
void delete_(std::span<VertexArray> s) {
    delete_vertex_arrays(
        static_cast<GLsizei>(size(s)),
        data(s));
}

}
