/// @file menu_io.h
#ifndef MENU_IO_H 
#define MENU_IO_H 
 
#include "menu_choice.h"
#include <exception>
#include <vector>

/**
 * @brief Gets a >=0 index from std::cin.
 * @param[in] choices Vector of menu choices for user to choose from
 * @return Correct index to acces element from choices
 * @throws bad_menu_idx Thrown if user input is out of available range(size of choices vector)
 */
auto read_menu_index(const std::vector<menu_choice>& choices) -> size_t;


/**
 * @brief Reads a size_t value from std::cin.
 * @param[in] mc An object to getPrompt() from
 * @return size_t from std::cin
 * @throws bad_str Thrown if any errors occured while reading from std::cin
 * @details
 * Prints mc.getPrompt() to std::cout.
 * Reads size_t from std::cin, returns decremented value.
 * In case of any errors throws bad_str exception.
 */
auto read_item_index(const menu_choice& mc) -> size_t;


/**
 * @brief Returns false if program should stop it's process.
 * @return bool interpolated from std::cin
 * @throws bad_str Thrown in case of wrong input from std::cin
 * @details
 * Prompts user from std::cout.
 * Reads value from std::cin.
 * If value is 'Y' or 'y' returns true.
 * If value is 'N' or 'n' returns false.
 * In case of any other inputs throws bad_str exception.
 */
auto read_exit_choice() -> bool;

#endif
