#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int> &nums) {
        auto b = nums.begin();
        auto e = nums.end();
        while (b <= e) {
            auto m = b + (e - b) / 2;
            long l = (m - 1 < nums.begin()) ? LONG_MIN : *(m - 1);
            long r = (m + 1 >= nums.end()) ? LONG_MIN : *(m + 1);
            if (l<*m && * m> r) {
                return m - nums.begin();
            } else if (l < *m && *m < r) {
                b = m + 1;
            } else if (l > *m && *m > r) {
                e = m - 1;
            } else if (l < r) {
                b = m + 1;
            } else if (l > r) {
                e = m - 1;
            } else {
                b = m + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> in{1, 2, 1, 3, 5, 6, 4};
    int res = s.findPeakElement(in);
    assert(5 == res);
}