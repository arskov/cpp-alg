#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = n - 1;
      while (l < r) {
        long long sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          res.push_back({nums[i], nums[l], nums[r]});
          int lv = nums[l];
          int rv = nums[r];
          while (l < r && nums[l] == lv)
            l++;
          while (l < r && nums[r] == rv)
            r--;
        } else if (sum < 0)
          l++;
        else
          r--;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = s.threeSum(nums);
  (void)res;

  nums = {0, 1, 1};
  res = s.threeSum(nums);
  (void)res;

  nums = {0, 0, 0};
  res = s.threeSum(nums);
  (void)res;

  nums = {-2, 0, 1, 1, 2};
  res = s.threeSum(nums);
  (void)res;

  nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  res = s.threeSum(nums);
  (void)res;

  nums = {-1, 0, 1, 0};
  res = s.threeSum(nums);
  (void)res;

  nums = {3, 0, -2, -1, 1, 2};
  res = s.threeSum(nums);
  (void)res;
}
