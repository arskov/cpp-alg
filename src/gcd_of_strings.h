#pragma once
#include <string>

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2);

private:
    bool is_devider(string const &str, string_view const &pref);
};
