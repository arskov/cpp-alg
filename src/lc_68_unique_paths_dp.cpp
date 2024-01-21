#include <string>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution
{

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<long>> memo(m, vector<long>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    memo[i][j] = 1L;
                }
                else
                {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                }
            }
        }
        return static_cast<int>(memo[m - 1][n - 1]);
    }
};

int main()
{
    Solution s;
    assert(s.uniquePaths(3, 7) == 28);
    assert(s.uniquePaths(3, 2) == 3);
}