#pragma once

#include <agl/glsl/all.hpp>

namespace agl::common {

// BAD TEMPLATE PARAMETER, SIZE IS IRREVELANT
// DO SOMETHING MORE GENERIC
// DOESNT HANDLE OPEN/CLOSED TOO
template<std::size_t N>
struct Interval {
    // INVARIANT: lb < ub NOT ENFORCED
    Vec<float, N> lower_bound;
    Vec<float, N> upper_bound;
};

template<std::size_t N>
Interval(Vec<float, N>, Vec<float, N>) -> Interval<N>;

}