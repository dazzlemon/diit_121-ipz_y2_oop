#ifndef MENU_H
#define MENU_H

#include "furniture.h"
#include <iostream>
#include <functional>
#include <limits>

namespace Menu {
    namespace Options {
        class Option {
        public:
            std::string menu_str;
            std::function<void(std::vector<Furniture>&)> action;
            void print() const;
        };
    };

    /**
     * tries to convert str to size_t and put it to result
     * returns false:
     *  if string isnt convertable
     *  or result is bigger than amount of options
     *  or atol converted only part of the str
     * otherwise returns true*/
    bool try_str_to_option_index(const std::string& str, size_t& result, size_t max_val);

    /** calls print(this function must pint options too choose from, and takes input, until correct is chosen([1; max_val)), returns correct input*/
    size_t read_input(std::function<void()> print, size_t max_val);

    /** prints menu options and gets input[1; amount_of_options], returns index to the option*/
    size_t read_menu_choice(const std::vector<Options::Option>& options);

    /** allows to choose from options, activates chosen one, repeats until exit is chosen*/
    void menu(const std::vector<Options::Option>& options, std::vector<Furniture>& furniture);

    /** takes input [1; UINT_MAX]*/
    size_t read_uint_choice(const std::string& message);

    /** prints enumerated options, one per line*/
    void print_menu(const std::vector<Options::Option>& options);

    /** prints enumerated options, one per line*/
    template<class T>
    void print_options(const std::vector<T>& options) {
        for(size_t i = 0; i < options.size(); i++){
            std::cout << i + 1 << ". ";
            options[i].print();
            std::cout << "\n";
        }
    }

    /** T has to have print(), to be shown on the screen*/
    template<class T>//to be abe to print other types of goods
    size_t read_goods_choice(std::vector<T>& goods) {
        std::function<void()> print = [&](){
            std::cout << "Please choose goods:\n\n";
            print_options(goods);};
        return read_input(print, goods.size() + 1) - 1;
    }
};
#endif
