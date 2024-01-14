#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int s : spells)
        {
            auto b = potions.begin();
            auto e = potions.end();
            while (b < e)
            {
                auto m = b + (e - b) / 2;
                long long guess = static_cast<long long>(s) * (*m);
                if (guess >= success)
                {
                    e = m;
                }
                else
                {
                    b = m + 1;
                }
            }
            res.push_back(potions.end() - e);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> spells{36, 36, 22, 11, 35, 21, 4, 25, 30, 35, 31, 10, 8, 39, 7, 22, 18, 9, 23, 30, 9, 37, 22, 7, 36, 40, 17, 37, 38, 27, 6, 15, 1, 15, 7, 31, 36, 29, 9, 15, 3, 37, 15, 17, 25, 35, 9, 21, 5, 17, 25, 8, 18, 25, 7, 19, 4, 33, 9, 5, 29, 13, 9, 18, 5, 10, 31, 6, 7, 24, 13, 11, 8, 19, 2};
    vector<int> potions{30, 11, 5, 20, 19, 36, 39, 24, 20, 37, 33, 22, 32, 28, 36, 24, 40, 27, 36, 37, 38, 23, 39, 11, 40, 19, 37, 32, 25, 29, 28, 37, 31, 36, 32, 40, 38, 22, 17, 38, 20, 33, 29, 17, 36, 33, 35, 25, 28, 18, 17, 19, 40, 27, 40, 28, 40, 40, 40, 39, 17, 34, 36, 11, 22, 29, 22, 35, 35, 22, 18, 34};
    vector<int> expected{72, 72, 71, 68, 72, 71, 29, 71, 72, 72, 72, 68, 68, 72, 59, 71, 71, 68, 71, 72, 68, 72, 71, 59, 72, 72, 71, 72, 72, 72, 51, 71, 0, 71, 59, 72, 72, 72, 68, 71, 0, 72, 71, 71, 71, 72, 68, 71, 46, 71, 71, 68, 71, 71, 59, 71, 29, 72, 68, 46, 72, 71, 68, 71, 46, 68, 72, 51, 59, 71, 71, 68, 68, 71, 0};
    auto res = s.successfulPairs(spells, potions, 135);
    assert(res == expected);
}