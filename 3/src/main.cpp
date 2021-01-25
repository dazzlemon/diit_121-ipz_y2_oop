#include "std_string.h"
#include <iostream>

int main() {
    std::cout << "std_string::count = " << std_string::quantity() << "\n";
    {
        std_string s1, s2, s3 = "test";
        std::cout << "s3 = \"" << s3 << "\"\n";
        std::cout << "(s3==\"test\") evaluates to: " << std::boolalpha << (s3 == "test") << "\n";
        std::cout << "(s3==\"tes\") evaluates to: " << std::boolalpha << (s3 == "tes") << "\n";
        std::cout << "std_string::count = " << std_string::quantity() << "\n";
    }
    std::cout << "std_string::count = " << std_string::quantity() << "\n";
}
