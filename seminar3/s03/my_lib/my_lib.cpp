#include "my_lib.h"

namespace my_lib {

    std::string shuffle(const std::string& str, const std::vector<int>& idx) {
        int n = (int)str.size();      
        std::string res(n, ' ');     

        for (int i = 0; i < n; ++i) {
            res[idx[i]] = str[i];     
        }

        return res;
    }

}
