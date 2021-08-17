#pragma once

#include "agl/common/scoped.hpp"

namespace agl {

template<typename Type>
concept NameTraits = true;

template<NameTraits NT>
struct Name {
    GLuint id = 0;

    constexpr
    Name() noexcept {}

    explicit
    Name(GLuint id) noexcept
        : id(id)
    {}

    constexpr
    operator bool() const noexcept {
        return id;
    }

    constexpr
    operator GLuint() const noexcept {
        return id;
    }
};

// template<NameTraits NT>
// struct Scoped<Name<NT>> : Name<NT> {
//     Scoped() noexcept {}

//     Scoped(Name<NT>&& n) noexcept
//         : Name<NT>(n)
//     {}

//     Scoped(const Scoped&) = delete;

//     Scoped(Scoped&& s) noexcept
//         : Name<NT>(s)
//     {
//         s.id = 0;
//     }

//     Scoped& operator=(const Scoped& s) = delete;

//     Scoped& operator=(Scoped&& s) noexcept {
//         NT::delete_(*this);
//         Name<NT>::id = s.id;
//         s.id = 0;
//         return *this;
//     }

//     ~Scoped() noexcept {
//         NT::delete_(*this);
//     }
// };

// template<typename Traits>
// auto scoped(Name<Traits> n) {
//     return Scoped<Traits>(n);
// }

////////////////////////////////////////////////////////////////////////////////
// Buffer.

struct BufferTraits {
    static void delete_(GLuint id) {
        glDeleteBuffers(1, &id);
    }
};

using Buffer = Name<BufferTraits>;

////////////////////////////////////////////////////////////////////////////////
// Framebuffer.

struct FramebufferTraits {
    static void delete_(GLuint id) {
        glDeleteFramebuffers(1, &id);
    }
};

using Framebuffer = Name<FramebufferTraits>;

////////////////////////////////////////////////////////////////////////////////
// Program.

struct ProgramTraits {
    static void delete_(GLuint id) {
        glDeleteProgram(id);
    }
};

using Program = Name<ProgramTraits>;

////////////////////////////////////////////////////////////////////////////////
// Sampler.

struct SamplerTraits {
    static void delete_(GLuint id) {
        glDeleteSamplers(1, &id);
    }
};

using Sampler = Name<SamplerTraits>;

////////////////////////////////////////////////////////////////////////////////
// Shader.

struct ShaderTraits {
    static void delete_(GLuint id) {
        glDeleteShader(id);
    }
};

using Shader = Name<ShaderTraits>;

////////////////////////////////////////////////////////////////////////////////
// Texture.

struct TextureTraits {
    static void delete_(GLuint id) {
        glDeleteTextures(1, &id);
    }
};

using Texture = Name<TextureTraits>;

////////////////////////////////////////////////////////////////////////////////
// VertexArray.

struct VertexArrayTraits {
    static void delete_(GLuint id) {
        glDeleteVertexArrays(1, &id);
    }
};

using VertexArray = Name<VertexArrayTraits>;

}