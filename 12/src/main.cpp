#include "gazetteer.h"
#include <iostream>

auto main() -> int {
	std::cout << "Ukraine: " << Gazetteer::getInfo("Ukraine") << std::endl;
	std::cout << "USA: " << Gazetteer::getInfo("USA") << std::endl;
	std::cout << "Spain: " << Gazetteer::getInfo("Spain") << std::endl;
}
