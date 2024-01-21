#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1);
        auto bits_set = [](int a)
        {
            int count = 0;
            // for (int i = 0; i < 32; i++) {
            //     count += (((a >> i) & 1) == 1);
            // }
            for (; a != 0; count++)
            {
                a &= a - 1;
            }
            return count;
        };
        for (int i = 0; i <= n; i++)
        {
            res[i] = bits_set(i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> expected1{0, 1, 1};
    assert(s.countBits(2) == expected1);
    vector<int> expected2{0, 1, 1, 2, 1, 2};
    assert(s.countBits(5) == expected2);
}