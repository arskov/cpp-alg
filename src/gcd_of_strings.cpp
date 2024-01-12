#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
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

private:
    bool is_devider(string const &str, string_view const &pref)
    {
        int times = str.length() / pref.length();
        string tmp;
        for (int i = 0; i < times; i++)
        {
            tmp += pref;
        }
        return str == tmp;
    }
};

int main() {
    Solution s;
    std::string res = s.gcdOfStrings("ABCDABCD", "ABCD");
    std::cout << res << std::endl;
    return 0;
}