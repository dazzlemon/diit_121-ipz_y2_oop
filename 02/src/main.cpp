#include "menu.h"
int main() {
    const std::vector<Menu::Options::Option> options {
        {"Increase price of goods.", [](std::vector<Furniture>& furniture) {
                size_t index = Menu::read_goods_choice(furniture);
                size_t inc = Menu::read_uint_choice("Please input by how much you want to increase price of goods:");
                furniture[index] += inc;
            }},
        {"Decrease price of goods.", [](std::vector<Furniture>& furniture) {
                size_t index = Menu::read_goods_choice(furniture);
                size_t dec = Menu::read_uint_choice("Please input by how much you want to decrease price of goods:");
                furniture[index] - dec;
            }},
        {"Compare two items.", [](std::vector<Furniture>& furniture) {
                size_t index_lhs = Menu::read_goods_choice(furniture);
                size_t index_rhs = Menu::read_goods_choice(furniture);
                std::cout << "Goods are";
                if (furniture[index_lhs] != furniture[index_rhs])
                    std::cout << "n't";
                std::cout << " equal!\n";
                std::cout << "Press any key to continue:\n";
                std::cin.ignore();
                std::cin.get();
            }},
        {"Print list of goods.", [](std::vector<Furniture>& furniture) {
                Menu::print_options(furniture);
                std::cout << "Press any key to continue:\n";
                std::cin.ignore();
                std::cin.get();
            }},
    };
    std::vector<Furniture> furniture {{"f1", 0, {1, 1, 1}}, {"f2", 1, {1, 1, 1}}};
    Menu::menu(options, furniture);
}
