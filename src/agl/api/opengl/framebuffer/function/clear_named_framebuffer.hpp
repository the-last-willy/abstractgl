#pragma once

namespace agl::opengl {

// How to handle default framebuffer (= 0) ?
inline
void ClearNamedFramebuffer(
    GLuint framebuffer,
	GLenum buffer,
	GLint drawbuffer,
	GLfloat value)
{
    glClearNamedFramebufferfv(
        framebuffer,
        buffer,
        drawbuffer,
        &value);
}

}