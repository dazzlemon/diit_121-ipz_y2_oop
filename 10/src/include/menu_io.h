#ifndef MENU_IO_H 
#define MENU_IO_H 
 
#include "menu_choice.h"
#include <exception>
#include <vector>
  
auto read_menu_index(const std::vector<menu_choice>& choices) -> size_t;
auto read_item_index(const menu_choice& mc) -> size_t;
auto read_exit_choice() -> bool;

#endif
