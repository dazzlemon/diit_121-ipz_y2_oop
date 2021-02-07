#include "exceptions.h"
#include "menu_choice.h"
#include "menu_io.h"
#include <cstddef>
#include <iostream>
#include <vector>

auto main() -> int {
	std::vector<int> items;

	auto item_idx_getter = [max = items.size()] () -> std::string {return "size of array is: " + std::to_string(max) + ", choose index to check: ";};
	std::vector<menu_choice> choices {
		menu_choice(
			"Get value @index.",
			item_idx_getter,
			[items] (size_t idx) {std::cout << "value at " + std::to_string(idx) + " is: " + std::to_string(items[idx]);}
		),
		menu_choice(
			"Insert value after index.",
			item_idx_getter,
			[] (size_t idx) {idx++;}
		),
		menu_choice(
			"Erase value @index.",
			item_idx_getter,
			[] (size_t idx) {idx++;}
		)
	};
  
	auto is_running = true;
	while (is_running) {
		try {
			auto menu_idx = read_menu_index(choices);
			auto item_idx = read_item_index(choices[menu_idx]);
			choices[menu_idx](item_idx);
		} catch (bad_str& e) {
			std::cout << "Invalid input!" << std::endl;
		} catch (bad_menu_idx& e) {
			std::cout << "Out of range menu choice!" << std::endl;
		} catch (bad_item_idx& e) {
			std::cout << "Out of range item choice!" << std::endl;
		}
		is_running = read_exit_choice();
  }
}
