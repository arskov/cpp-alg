#include "gcd_of_strings.h"
#include <iostream>

int main()
{
    Solution s;
    std::string res = s.gcdOfStrings("ABCDABCD", "ABCD");
    std::cout << res << std::endl;
    return 0;
}