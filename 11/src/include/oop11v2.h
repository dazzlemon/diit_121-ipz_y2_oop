/// @file oop11v2.h
#ifndef OOP11V2_H
#define OOP11V2_H

#include <functional>
#include <list>

namespace v2 {
/**
 * @brief Returns intersections of f and g on range_.
 * @param[in] f y(x) function on 2d plane which exists for all xs in range_
 * @param[in] g y(x) function on 2d plane which exists for all xs in range_
 * @param[in] range_ Range on which intersections between f and g will be searched
 * @tparam N Floating point Numeric Type
 * @return list<N> of xs in which f and g intersect
 */
template<class N>
auto intersections(std::function<N(N)> f, std::function<N(N)> g, std::pair<N, N> range_) -> std::list<N>;


/**
 * @brief Returns num evenly spaced samples, calculate over the interval [start, stop].
 * @param[in] start The starting value of the sequence
 * @param[in] stop The end value of the sequence
 * @param[in] num Number of samples to generate
 * @tparam N Floating point Numeric Type
 * @return num equally spaced samples in the closed interval [start, stop]
 */ 
template<class N>
auto linspace(N start, N stop, size_t num) -> std::list<N>;


/**
 * @brief The sign function returns -1 if x < 0, 0 if x==0, 1 if x > 0.
 * @param[in] x input value
 * @tparam N Numeric Type
 * @return The sign of x
 */
template<class N>
auto sign(N x) -> int;


template<class N>
auto intersections(std::function<N(N)> f, std::function<N(N)> g, std::pair<N, N> range_) -> std::list<N> {
	const size_t NUMS = 1000;
	auto xs = linspace(range_.first, range_.second, NUMS);
	std::list<int> signs(NUMS);

	for (auto x = xs.begin(), s = signs.begin(); x != xs.end(); x++, s++) {
		*s = sign(f(*x) - g(*x));
	}

	auto res = std::list<N>();
	
	for (auto x = xs.begin(), s1 = signs.begin(), s2 = ++signs.begin(); s2 != signs.end(); x++, s1++, s2++) {
		if (*s1 - *s2 != 0) {
			res.push_back(*x);
		}
	}

	return res;
}


template<class N>
auto linspace(N start, N stop, size_t num) -> std::list<N> {
	std::list<N> l(num);
	N step = (stop -start) / (num - 1);
	N val = start;
	for (auto& i : l) {
		i = val;
		val += step;
	}
	return l;
}


template<class N>
auto sign(N x) -> int {
	return x > 0 ? 1
	     : x < 0 ? -1
	             : 0;
}

}//namespace v2
#endif
