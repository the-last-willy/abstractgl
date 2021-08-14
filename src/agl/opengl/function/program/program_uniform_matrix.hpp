#pragma once

#include "agl/glsl/mat/element_count.hpp"
#include "agl/glsl/mat/element_data.hpp"
#include "agl/glsl/mat/mat2.hpp"
#include "agl/glsl/mat/mat3.hpp"
#include "agl/glsl/mat/mat4.hpp"
#include "agl/opengl/names.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void uniform(
    Program p,
    UniformIndex ui,
    Mat2 m)
{
    glProgramUniformMatrix2fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

inline
void uniform(
    Program p,
    UniformIndex ui,
    const Mat3& m)
{
    glProgramUniformMatrix3fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

inline
void uniform(
    Program p,
    UniformIndex ui,
    const Mat4& m)
{
    glProgramUniformMatrix4fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

}
