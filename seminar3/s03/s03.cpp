#include <vector>
#include <string>
#include <iostream>
#include <iterator>     
#include "my_lib.h"    

int main() {
    std::vector<std::string> v {"a", "b", "d", "a", "add", "string"};

    v.push_back("cde");        
    v.emplace_back("zg");     
    v.pop_back();              

    auto it = v.begin();       
    std::advance(it, 4);       
    v.insert(it, 3, "str");    

    std::vector<int> vi {1, 2, 3, 4, 5};
    std::vector<double> vd {10.0, 13.3, 14.321};

    my_lib::pv(v);
    my_lib::pv(vi);
    my_lib::pv(vd);

    std::cout << "2^3 = " << my_lib::powN<int, 3>(2) << std::endl;

    // Пример shuffle
    std::string s = "abcd";
    std::vector<int> order = {3, 2, 1, 0};
    std::cout << "shuffle: " << my_lib::shuffle(s, order) << std::endl;

    return 0;
}
