#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
   public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        switch (n) {
            case 0:
                return 0;
            case 1:
                return cost[0];
            case 2:
                return min(cost[0], cost[1]);
        }
        unique_ptr<int[]> dp = make_unique<int[]>(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution s;
    vector<int> stairs1{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int res = s.minCostClimbingStairs(stairs1);
    assert(res == 6);
}