#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>&& nums) {
        int i = 0, j = 0, f = 1;
        for (; j < nums.size(); j++) {
            if (nums[j] == 0) {
                f--;
            }
            if (f < 0 && nums[i++] == 0) {
                f++;
            }
        }
        return j - i;
    }
};

int main() {
    Solution s;
    int res1 = s.findMaxConsecutiveOnes({1, 0, 1, 1, 0});
    assert(res1 == 4);
    int res2 = s.findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1});
    assert(res2 == 4);
}
