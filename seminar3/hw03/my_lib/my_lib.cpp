#include "my_lib.h"

namespace my_lib {

    std::string shuffle(const std::string& str, const std::vector<int>& idx) {
        int n = static_cast<int>(str.size());
        std::string res(n, ' '); 

        for (int i = 0; i < n; ++i) {
            if (i >= static_cast<int>(idx.size())) {
                
                break;
            }

            int pos = idx[i];

         
            if (pos < 0 || pos >= n) {
                continue;
            }

          
            res[pos] = str[i];
        }

        return res;
    }

} 
