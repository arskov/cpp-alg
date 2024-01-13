#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result;
        int small_size = min(word1.length(), word2.length());
        int large_size = max(word1.length(), word2.length());
        for (int i = 0; i < small_size; i++)
        {
            result += word1[i];
            result += word2[i];
        }
        auto large = word1.length() > word2.length() ? word1 : word2;
        result.append(large, small_size, large_size - small_size);
        return result;
    }
};

int main()
{
    Solution s;

    string a{"ab"};
    string b{"pqrs"};
    string exp1{"apbqrs"};

    string res = s.mergeAlternately(a, b);
    cout << "Expected: " << exp1 << ", Result: " << res << ", equals: " << (res == exp1) << endl;
}