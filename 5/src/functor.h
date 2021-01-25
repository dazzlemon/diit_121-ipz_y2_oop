#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <vector>
#include <algorithm>

template<class T>//T positive integral type
class Functor {
public:
    Functor(T state) : state{state} {}
    T state;
    void operator()(std::vector<T>& vec) {
        std::sort(vec.begin(), vec.end(), [&](const T& a, const T& b) {
            auto cmp = a <=> a;//std::compare_three_way_result_t<T> cant be uninitialized
            for (T state = this->state; cmp == 0 && state >= 0; state--)
                cmp = (gcd(a, state) <=> gcd(b, state));
            return cmp > 0;
        });
    }
private:
    int gcd(T a, T b) {
        T t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};
#endif
