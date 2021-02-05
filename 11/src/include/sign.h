#ifndef SIGN_H
#define SIGN_H

#include <concepts>

/**
 * @brief The sign function returns -1 if x < 0, 0 if x==0, 1 if x > 0.
 * @param[in] x input value
 * @tparam N Numeric Type ordererable with int
 * @return The sign of x
 */
template<class N>
	requires std::totally_ordered_with<N, int>
auto sign(N x) -> int;

template<class N>
	requires std::totally_ordered_with<N, int>
auto sign(N x) -> int {
	return x > 0 ? 1
	     : x < 0 ? -1
	             : 0;
}

#endif
