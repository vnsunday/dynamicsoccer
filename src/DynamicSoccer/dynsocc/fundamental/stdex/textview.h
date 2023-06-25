#ifndef DYNSOCC_FUNDAMENTAL_STDEX_TEXTVIEW_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_TEXTVIEW_H_

#include <vector>
#include <string>

namespace dynsocc
{

    class TextView 
    {
    public:
        static int column_print(
            std::vector<int> vcol_size,
            std::vector<string> vcontent
        );
    };
}

#endif 