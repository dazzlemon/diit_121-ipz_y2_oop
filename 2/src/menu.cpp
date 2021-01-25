#include "menu.h"

void Menu::Options::Option::print() const {
    std::cout << menu_str;
}

void Menu::print_menu(const std::vector<Options::Option> &options){
    system("clear");
    std::cout << "Choose what you want to do:\n";
    print_options(options);
    std::cout << options.size() + 1 << ". Exit.\n";
}

bool Menu::try_str_to_option_index(const std::string& str, size_t& result, size_t max_val) {
    result = atol(str.c_str());
    return result != 0 && result <= max_val && std::to_string(result) == str;
}

void Menu::menu(const std::vector<Options::Option>& options, std::vector<Furniture>& furniture) {
    size_t choice;
    while((choice = read_menu_choice(options)) < options.size()) {
        options[choice].action(furniture);
    }
}

size_t Menu::read_uint_choice(const std::string& message) {
    std::function<void()> print = [&](){std::cout << message;};
    return read_input(print, std::numeric_limits<size_t>::max());
}

size_t Menu::read_menu_choice(const std::vector<Options::Option>& options) {
    std::function<void()> print = [&](){print_menu(options);};
    return read_input(print, options.size() + 1) - 1;
}

size_t Menu::read_input(std::function<void()> print, size_t max_val) {
    size_t input;
    bool good = true;
    do {
        print();
        if (!good)
            std::cout << "Invalid choice! Try again.\n";
        std::string choice;
        std::cin >> choice;
        good = try_str_to_option_index(choice, input, max_val);
    } while (!good);
    return input;
}
