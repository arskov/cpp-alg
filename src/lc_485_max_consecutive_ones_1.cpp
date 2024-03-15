#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>&& nums) {
        int count = 0, max_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 0;
            }
        }
        return max(max_count, count);
    }
};

int main() {
    Solution s;
    int res1 = s.findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1});
    assert(res1 == 2);
    int res2 = s.findMaxConsecutiveOnes({1, 1, 0, 1, 1, 1});
    assert(res2 == 3);
}