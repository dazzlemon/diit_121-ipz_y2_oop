/// @file read.h
#ifndef READ_H
#define READ_H

#include "exceptions.h"
#include <iostream>
#include <menu_io.h>

/**
 * @brief Returns T object read from std::cin.
 * @tparam T Type to be read from std::cin
 * @return T object read from std::cin
 * @throws bad_str Thrown if any errors occured while reading from std::cin
 * @details
 * Tries to read T object from std::cin.
 * In case of any errors throws bad_str exception.
 */
template<class T>
auto read() -> T {
	T res;
	std::cin >> res;
	if (!std::cin || std::cin.get() != '\n') {
		std::cin.clear();
		while (std::cin.get() != '\n') {}

		throw bad_str();
	}
	return res;
}

#endif
