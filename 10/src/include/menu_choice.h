#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

#include <cstddef>
#include <functional>
#include <string>

class menu_choice {
	std::string str;
	std::function<std::string()> prompt;
	std::function<void(size_t)> callable;
public:
	menu_choice(std::string str, std::function<std::string()> prompt, std::function<void(size_t)> callable) 
			: str(std::move(str)), prompt(std::move(prompt)), callable(std::move(callable)) {}

	void operator() (size_t idx) const {this->callable(idx);}
	[[nodiscard]] auto getStr() const -> std::string {return this->str;}
	[[nodiscard]] auto getPrompt() const -> std::string {return this->prompt();}
};
#endif
