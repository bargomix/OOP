#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace my_lib {


    template <typename T>
    void pv(const std::vector<T>& vec) {
        for (const auto& x : vec) {
            std::cout << x << ' ';
        }
        std::cout << std::endl;
    }


    template <typename T, int P = 2>
    T powN(T x) {
        T result = 1;
        for (int i = 0; i < P; ++i) {
            result *= x;
        }
        return result;
    }

 
    std::string shuffle(const std::string& str, const std::vector<int>& idx);

  
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

   
    template <typename T>
    T sub(T a, T b) {
        return a - b;
    }

  
    template <typename T>
    T mul(T a, T b) {
        return a * b;
    }

 
    template <typename T>
    T divide(T a, T b) {
        if (b == 0) {
            return T{}; 
        }
        return a / b;
    }

  
    template <typename T, typename F>
    T apply_op(T a, T b, F f) {
        return f(a, b);
    }

} // namespace my_lib
