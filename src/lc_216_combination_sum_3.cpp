#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res, curr, 1, k, n);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, vector<int> &curr, int start, int k, int n)
    {
        if (curr.size() == k)
        {
            if (accumulate(curr.begin(), curr.end(), 0) == n)
            {
                res.push_back(curr);
            }
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            curr.push_back(i);
            dfs(res, curr, i + 1, k, n);
            curr.pop_back();
        }
    }
};

int main()
{
    Solution s;
    auto res = s.combinationSum3(3, 7);
    vector<vector<int>> exp{{1, 2, 4}};
    assert(res == exp);
}
