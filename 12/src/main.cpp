#include "gazetteer.h"
#include <iostream>

auto main() -> int {
	std::cout << Gazetteer::getInfo("Ukraine") << std::endl;
}
