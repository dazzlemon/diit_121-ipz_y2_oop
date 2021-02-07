#include "exceptions.h"
#include "menu_choice.h"
#include "menu_io.h"
#include "read.h"
#include <cstddef>
#include <iostream>
#include <vector>

auto main() -> int {
	std::vector<int> items;

	auto item_idx_getter = [&] () -> std::string {return "size of array is: " + std::to_string(items.size()) + ", choose index: ";};
	std::vector<menu_choice> choices {
		menu_choice(
			"Insert value @index.",
			item_idx_getter,
			[&] (size_t idx) {
				if (idx > items.size()) {
					throw bad_item_idx();
				}
				std::cout << "Input a integer to insert @" << idx + 1 << ":" << std::endl;
				auto i = read<int>();
				items.insert(items.begin() + idx, i);
			}
		),
		menu_choice(
			"Erase value @index.",
			item_idx_getter,
			[&] (size_t idx) {
				if (idx >= items.size()) {
					throw bad_item_idx();
				}
				items.erase(items.begin() + idx);
			}
		)
	};
  
	auto is_running = true;
	while (is_running) {
		try {
			std::cout << "array: ";
			for (auto i : items) {
				std::cout << i << " ";
			}
			std::cout << std::endl;
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

		bool got_choice = false;

		while (!got_choice) {
			try {
				is_running = read_exit_choice();
				got_choice = true;
			} catch (bad_str& e) {
				std::cout << "Invalid input, try again." << std::endl;
			}
		}
  }
}
