#include "gcd_of_strings.h"
#include <iostream>

using namespace std;

string Solution::gcdOfStrings(string str1, string str2)
{
    if ((str1 + str2) != (str2 + str1))
        return "";
    string res{""};
    for (size_t i = 1; i <= str2.length(); i++)
    {
        string_view pref(str2.data(), i);
        if (is_devider(str1, pref) && is_devider(str2, pref))
        {
            res = pref;
        }
    }
    return res;
}

bool Solution::is_devider(string const &str, string_view const &pref)
{
    int times = str.length() / pref.length();
    string tmp;
    for (int i = 0; i < times; i++)
    {
        tmp += pref;
    }
    return str == tmp;
}
