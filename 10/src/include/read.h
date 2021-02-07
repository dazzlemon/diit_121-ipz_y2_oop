#ifndef READ_H
#define READ_H

#include "exceptions.h"
#include <iostream>
#include <menu_io.h>

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
