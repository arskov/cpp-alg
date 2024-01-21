#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
   public:
    int singleNumber(vector<int> &&nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a ^= b; });
    }
};

int main() {
    Solution s;
    assert(s.singleNumber({4, 1, 2, 1, 2}) == 4);
    assert(s.singleNumber({2, 2, 1}) == 1);
}