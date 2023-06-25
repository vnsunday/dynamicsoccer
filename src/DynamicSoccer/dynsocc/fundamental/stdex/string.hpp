#ifndef DYNSOCC_FUNDAMENTAL_STDEX_STRING_HPP_
#define DYNSOCC_FUNDAMENTAL_STDEX_STRING_HPP_

#include <string>
#include <vector>

namespace dynsocc
{

    class stringutil
    {
    public:
        static int find(std::string src, std::string tofind, std::vector<int>& vres);

		static int compare(unsigned int* p1, int n1, unsigned int* p2, int n2);

		static int fuzzy_search(unsigned int* str, int n);

		static std::string format_number_thousand_separator(double number, int& res, char ch_separator = '\'');
    };


}

#endif 