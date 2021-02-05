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
 * @return vector<N> of xs in which f and g intersect
 */
template<class N>
auto intersections(std::function<N(N)> f, std::function<N(N)> g, std::pair<N, N> range_) -> std::vector<N>;


/**
 * @brief Returns num evenly spaced samples, calculate over the interval [start, stop].
 * @param[in] start The starting value of the sequence
 * @param[in] stop The end value of the sequence
 * @param[in] num Number of samples to generate
 * @tparam N Floating point Numeric Type
 * @return num equally spaced samples in the closed interval [start, stop]
 */ 
template<class N>
auto linspace(N start, N stop, size_t num) -> std::vector<N>;


/**
 * @brief The sign function returns -1 if x < 0, 0 if x==0, 1 if x > 0.
 * @param[in] x input value
 * @tparam N Numeric Type
 * @return The sign of x
 */
template<class N>
auto sign(N x) -> int;


template<class N>
auto intersections(std::function<N(N)> f, std::function<N(N)> g, std::pair<N, N> range_) -> std::vector<N> {
}


template<class N>
auto linspace(N start, N stop, size_t num) -> std::vector<N> {
}


template<class N>
auto sign(N x) -> int{
	return x > 0 ? 1
			 : x < 0 ? -1
							 : 0;
}

}//namespace v2
#endif
