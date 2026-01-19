#include <iostream>
#include <vector>
#include <string>
#include <iterator>   
#include "my_lib/my_lib.h"

int main() {
    std::vector<std::string> vs{"a", "b", "d", "a", "add", "string"};

    vs.push_back("cde");
    vs.emplace_back("zg");
    vs.pop_back();

    auto it = vs.begin();
    std::advance(it, 4);
    vs.insert(it, 3, "str");

    std::vector<int> vi{1, 2, 3, 4};
    std::vector<double> vd{10.0, 13.3, 14.321};

    std::cout << "vs = ";
    my_lib::pv(vs);

    std::cout << "vi = ";
    my_lib::pv(vi);

    std::cout << "vd = ";
    my_lib::pv(vd);

    std::cout << "2^3 (powN<int,3>) = "
              << my_lib::powN<int, 3>(2) << std::endl;

    std::string s = "abcd";
    std::vector<int> idx{2, 0, 3, 1};

    std::cout << "shuffle(\"" << s << "\") = "
              << my_lib::shuffle(s, idx) << std::endl;

    // --- Демонстрация операций и высшей функции ---
    int a = 10;
    int b = 5;

    std::cout << "add(a, b) = " << my_lib::add(a, b) << std::endl;
    std::cout << "sub(a, b) = " << my_lib::sub(a, b) << std::endl;
    std::cout << "mul(a, b) = " << my_lib::mul(a, b) << std::endl;
    std::cout << "divide(a, b) = " << my_lib::divide(a, b) << std::endl;
    std::cout << "divide(a, 0) (аварийный случай) = "
              << my_lib::divide(a, 0) << std::endl;

    // Высшая функция: передаём нашу операцию как параметр
    int sum_via_apply = my_lib::apply_op<int>(a, b, my_lib::add<int>);
    int mul_via_apply = my_lib::apply_op<int>(a, b, my_lib::mul<int>);

    std::cout << "apply_op(a, b, add) = " << sum_via_apply << std::endl;
    std::cout << "apply_op(a, b, mul) = " << mul_via_apply << std::endl;

    return 0;
}


//cmake .. -DBUILD_TESTS_FOR_LIB=ON