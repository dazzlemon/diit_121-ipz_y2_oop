#ifndef STD_STRING_H
#define STD_STRING_H

#include <string>

class std_string : public std::string {
    static int count;
public:
    using std::string::operator=;
    using std::string::operator+=;
    using std::string::operator[];
    std_string() : std::string() {count++;}
    std_string (const std::string& str) : std::string(str) {count++;}
    std_string (const std::string& str, size_t pos, size_t len = npos) : std::string(str, pos, len) {count++;}
    std_string (const char* s) : std::string(s) {count++;}
    std_string (const char* s, size_t n) : std::string(s, n) {count++;}
    std_string (size_t n, char c) : std::string(n, c) {count++;}
    template <class InputIterator>
      std_string  (InputIterator first, InputIterator last) : std::string(first, last) {count++;}
    ~std_string() {count--;}//calls std::string destructor, then this
    static int quantity() {return count;};
};
#endif
