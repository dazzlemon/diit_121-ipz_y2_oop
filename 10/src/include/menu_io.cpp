#include "exceptions.h"
#include "menu_choice.h"
#include "menu_io.h"
#include "read.h"
#include <iostream>

auto read_menu_index(const std::vector<menu_choice>& choices) -> size_t {
	for (size_t i = 0; i < choices.size(); i++) {
		std::cout << i + 1 << ". " << choices[i].getStr() << std::endl;
	}
	auto r = read<size_t>();
	if (r > choices.size()) {
		throw bad_menu_idx();
	}
	return r - 1;
}


auto read_item_index(const menu_choice& mc) -> size_t {
	std::cout << mc.getPrompt() << std::endl;
	return read<size_t>() - 1;
}


auto read_exit_choice() -> bool {
	std::cout << "Do you want to continue?(y/n)" << std::endl;
	auto res = read<char>();
	if (res == 'y' || res == 'Y') {
		return true;
	} 
	if (res == 'n' || res == 'N') {
		return false;
	}
	throw bad_str();
}

