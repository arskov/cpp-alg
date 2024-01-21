#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    // int dp(string& w1, int i, string& w2, int j, vector<vector<int>>& memo) {
    //     if (i == w1.size() && j == w2.size()) {
    //         return 0;
    //     } else if (i == w1.size()) {
    //         return static_cast<int>(w2.size()) - j;
    //     } else if (j == w2.size()) {
    //         return static_cast<int>(w1.size()) - i;
    //     }
    //     if (memo[i][j] != INT_MAX) return memo[i][j];
    //     int a = dp(w1, i + 1, w2, j + 1, memo) + (w1[i] == w2[j] ? 0 : 1);
    //     int b = min(dp(w1, i + 1, w2, j, memo), dp(w1, i, w2, j + 1, memo)) + 1;
    //     int val = min(a, b);
    //     memo[i][j] = val;
    //     return val;
    // }

   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, INT_MAX));

        function<int(int, int)> dp;
        dp = [&dp, &word1, &word2, n, m, &memo](int i, int j) {
            if (i == word1.size() && j == word2.size())
                return 0;
            else if (i == word1.size())
                return static_cast<int>(word2.size()) - j;
            else if (j == word2.size())
                return static_cast<int>(word1.size()) - i;

            if (memo[i][j] != INT_MAX) return memo[i][j];
            int a = dp(i + 1, j + 1) + (word1[i] == word2[j] ? 0 : 1);
            int b = min(dp(i + 1, j), dp(i, j + 1)) + 1;
            int val = min(a, b);
            memo[i][j] = val;
            return val;
        };

        return dp(0, 0);
    }
};

int main() {
    Solution s;
    assert(s.minDistance("horse", "ros") == 3);
    assert(s.minDistance("intention", "execution") == 5);
}