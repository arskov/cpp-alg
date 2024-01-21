#include <vector>
#include <cassert>

using namespace std;

class Solution
{
private:
    int dp(vector<int> &prices, int i, int tx, vector<vector<int>> &memo, int fee)
    {
        if (i == prices.size())
            return 0;
        if (memo[tx][i] != INT_MIN)
            return memo[tx][i];
        int val;
        if (tx == 0)
        {
            val = max(
                dp(prices, i + 1, 0, memo, fee),
                dp(prices, i + 1, 1, memo, fee) - prices[i]);
        }
        else
        {
            val = max(
                dp(prices, i + 1, 0, memo, fee) + prices[i] - fee,
                dp(prices, i + 1, 1, memo, fee));
        }
        memo[tx][i] = val;
        return val;
    }

public:
    int maxProfit(vector<int> &&prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> memo(2, vector<int>(n, INT_MIN));
        return max(
            dp(prices, 0, 0, memo, fee),
            dp(prices, 0, 1, memo, fee) - prices[0]);
    }
};

int main()
{
    Solution s;
    assert(s.maxProfit({1, 2, 3, 4, 5, 6}, 2) == 3);
    assert(s.maxProfit({6, 5, 4, 3, 2, 1}, 2) == 0);
    assert(s.maxProfit({1, 3, 2, 8, 4, 9}, 2) == 8);
    assert(s.maxProfit({1, 3, 7, 5, 10, 3}, 3) == 6);
}