#include <iostream>
#include "functor.h"

template <class T>
void print_vec(std::vector<T>& v){
    for (auto& c : v)
        std::cout << c << " ";
    std::cout << "\n";
}

int main() {
    Functor f(7);
    std::vector v{15, 24, 56, 66};
    std::cout << "state = " << f.state << "\n";
    std::cout << "presort\n";
    print_vec(v);

    f(v);
    // 15, 24, 56, 66, state = 7
    //   7: 56
    //   6: 24, 66 -> 4: 24, 3: 66
    //   5: 15
    //     56, 24, 66, 15

    std::cout << "postort\n";
    print_vec(v);
}
