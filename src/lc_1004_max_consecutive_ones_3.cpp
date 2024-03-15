#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>&& nums, int k) {
        int i = 0, j = 0;
        for (; j < nums.size(); j++) {
            if (nums[j] == 0) k--;
            if (k < 0 && nums[i++] == 0) {
                k++;
            }
        }
        return j - i;
    }
};

int main() {
    Solution s;
    int res = s.longestOnes({0,0,0}, 1);
    cout << "Res: " << res << endl;
    assert(res == 1);
    res = s.longestOnes({0,0,1}, 1);
    cout << "Res: " << res << endl;
    assert(res == 2);
    res = s.longestOnes({1,1,1}, 1);
    cout << "Res: " << res << endl;
    assert(res == 3);
    res = s.longestOnes({1,0,1}, 1);
    cout << "Res: " << res << endl;
    assert(res == 3);
    res = s.longestOnes({1,0,0,1}, 1);
    cout << "Res: " << res << endl;
    assert(res == 2);
    res = s.longestOnes({1,0,1,1,0,0,1,1,1,0,1,1}, 1);
    cout << "Res: " << res << endl;
    assert(res == 6);
}