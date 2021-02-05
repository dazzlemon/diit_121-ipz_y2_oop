#ifndef SORT_H
#define SORT_H

#include <concepts>
#include <cstddef>
#include <utility>
#include <vector>

/**
 * @brief sorts elements of array.
 * @param[in] a Array to be sorted
 * @param[in] lo Index of first element to be sorted
 * @param[in] hi Index of last element to be sorted
 * @tparam Orderable type
 */
template<class T>
	requires std::totally_ordered<T>
void quicksort(std::vector<T>& a, size_t lo, size_t hi);

namespace details {
template<class T>
	requires std::totally_ordered<T>
auto partition(std::vector<T>& a, size_t lo, size_t hi) -> size_t;

template<class T>
	requires std::totally_ordered<T>
auto partition(std::vector<T>& a, size_t lo, size_t hi) -> size_t {
	auto pivot = a[hi];
	auto i = lo;
	for (auto j = lo; j <= hi; j++) {
		if (a[j] < pivot) {
			std::swap(a[i++], a[j]);
		}
	}
	std::swap(a[i], a[hi]);
	return i;
}

}//namespace details


template<class T>
	requires std::totally_ordered<T>
void quicksort(std::vector<T>& a, size_t lo, size_t hi) {
  if (lo < hi) {
    auto p = details::partition(a, lo, hi);
		if (p > 0) {
			quicksort(a, lo, p - 1);
		}
    quicksort(a, p + 1, hi);
	}
}

#endif
