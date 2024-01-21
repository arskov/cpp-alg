#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    int dp(string &text1, int n, string &text2, int m, vector<vector<int>> &memo) {
        if (n == text1.size() || m == text2.size()) return 0;
        if (memo[n][m] != -1) return memo[n][m];
        int val;
        if (text1[n] == text2[m]) {
            val = 1 + dp(text1, n + 1, text2, m + 1, memo);
        } else {
            val = max(dp(text1, n + 1, text2, m, memo), dp(text1, n, text2, m + 1, memo));
        }
        memo[n][m] = val;
        return val;
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0) return 0;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dp(text1, 0, text2, 0, memo);
    }
};

int main() {
    Solution s;
    assert(s.longestCommonSubsequence("abcde", "ace") == 3);
    assert(s.longestCommonSubsequence("abc", "abc") == 3);
    assert(s.longestCommonSubsequence("abc", "def") == 0);
}