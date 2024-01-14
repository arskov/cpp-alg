#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>

using namespace std;

static unordered_map<char, string> BUTTONS{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string s;
        dfs(result, s, 0, digits);
        return result;
    }

private:
    void dfs(vector<string> &res, string &current, int start, string &digits)
    {
        if (digits.empty())
            return;
        if (current.size() == digits.size())
        {
            res.push_back(current);
            return;
        }
        for (int i = start; i < digits.size(); i++)
        {
            for (char &l : BUTTONS.at(digits[i]))
            {
                current.push_back(l);
                dfs(res, current, i + 1, digits);
                current.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<string> exp{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    auto res = s.letterCombinations("23");
    assert(res == exp);
    cout << "[";
    for (const auto& w : res) cout << w << ",";
    cout << "]" << endl;
}