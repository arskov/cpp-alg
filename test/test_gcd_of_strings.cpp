#include "gcd_of_strings.h"
#include <iostream>

void test_gcd_of_strings()
{
    Solution s;
    std::string res = s.gcdOfStrings("ABCDABCD", "ABCD");
    std::cout << res << std::endl;
}

int main()
{
    test_gcd_of_strings();
    return 0;
}