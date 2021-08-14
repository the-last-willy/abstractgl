#pragma once

#include "agl/opengl/qualifier/level.hpp"
#include "agl/opengl/qualifier/texture_attachment.hpp"
#include "agl/opengl/names.hpp"

namespace agl {

inline
void texture(
    Framebuffer f,
    TextureAttachment ta,
    Texture t,
    Level l = Level(0))
{
    glNamedFramebufferTexture(
        f,
        static_cast<GLenum>(ta),
        t,
        l);
}

}