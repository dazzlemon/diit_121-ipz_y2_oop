#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class bad_str : std::exception {};
class bad_menu_idx : std::exception {};
class bad_item_idx : std::exception {};

#endif
