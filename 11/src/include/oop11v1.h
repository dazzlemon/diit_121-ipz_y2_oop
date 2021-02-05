/// @file oop11v1.h
#ifndef OOP11V1_H
#define OOP11V1_H

#include <algorithm>
#include <cmath>
#include <functional>
#include <ranges>
#include <vector>

namespace v1 {
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
	const size_t NUMS = 1000;
	auto xs = linspace(range_.first, range_.second, NUMS);
	auto signs = xs | std::views::transform([f, g] (auto x) {return sign(f(x) - g(x));});
	auto signs_vec = std::vector(signs.begin(), signs.end());
	std::transform(signs_vec.begin(), signs_vec.end(), ++signs_vec.begin(), signs_vec.begin(), [] (auto a, auto b) {return a - b;});
	std::transform(xs.begin(), xs.end(), signs_vec.begin(), xs.begin(), [] (auto x, auto sign_) {return sign_ == 0 ? INFINITY : x;});
	auto res = xs | std::views::filter([] (auto x) {return x != INFINITY;});
	return std::vector(res.begin(), --res.end());//last num wasnt checked
}


template<class N>
auto linspace(N start, N stop, size_t num) -> std::vector<N> {
	std::vector<N> vec(num);
	N step = (stop - start) / (num - 1);
	std::generate(vec.begin(), vec.end(), [n = start - step, step] () mutable {n += step; return n;});
	return vec;
}


template<class N>
auto sign(N x) -> int {
	return x > 0 ? 1
			 : x < 0 ? -1
							 : 0;
}

}//namespace v1
#endif
