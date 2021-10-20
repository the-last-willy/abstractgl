#pragma once

#include "agl/engine/triangle_mesh/mesh/mesh.hpp"

namespace agl::engine {

// RENAME INTO FACE INSTEAD

struct MutableTriangleProxy {
    MutableTriangleProxy(TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    MutableTriangleProxy(TriangleMesh& tm, uint32_t i) 
        : MutableTriangleProxy(&tm, i)
    {}

    TriangleMesh* mesh;
    uint32_t index;
};

struct ConstTriangleProxy {
    ConstTriangleProxy(const TriangleMesh* tm, uint32_t i) 
        : mesh(tm)
        , index(i)
    {}

    ConstTriangleProxy(const TriangleMesh& tm, uint32_t i) 
        : ConstTriangleProxy(&tm, i)
    {}

    ConstTriangleProxy(MutableTriangleProxy mtp)
        : ConstTriangleProxy(*mtp.mesh, mtp.index)
    {}

    const TriangleMesh* mesh;
    uint32_t index;
};

}