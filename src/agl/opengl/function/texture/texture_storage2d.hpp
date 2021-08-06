#pragma once

#include "agl/opengl/qualifier/level.hpp"
#include "agl/opengl/names.hpp"
#include "agl/opengl/qualifier/height.hpp"
#include "agl/opengl/qualifier/width.hpp"

namespace agl {

inline
void storage(
    Texture t,
    GLsizei levels,
    GLenum internalformat,
    Width w,
    Height h)
{
    glTextureStorage2D(
        t,
        levels,
        internalformat,
        w,
        h);
}

inline
void storage(
    Texture t,
    GLenum internalformat,
    Width w,
    Height h)
{
    storage(
        t,
        1,
        internalformat,
        w,
        h);
}

}
