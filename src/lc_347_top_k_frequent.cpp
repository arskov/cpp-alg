#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> counter;
    int n = nums.size();
    counter.reserve(n);
    for (auto c : nums) {
      counter[c]++;
    }
    vector<vector<int>> buckets(n + 1);
    for (auto [num, freq] : counter) {
      buckets[freq].push_back(num);
    }
    vector<int> res;
    res.reserve(k);
    for (int j = buckets.size() - 1; j >= 0; j--) {
      if (!buckets[j].empty()) {
        for (auto num : buckets[j]) {
          res.push_back(num);
          k--;
          if (k == 0)
            return res;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  vector<int> nums1{1, 1, 1, 2, 2, 3};
  int k1 = 2;
  vector<int> res1 = s.topKFrequent(nums1, k1);
  sort(res1.begin(), res1.end());
  vector<int> expected1{1, 2};
  sort(expected1.begin(), expected1.end());
  assert(res1 == expected1);

  vector<int> nums2{1};
  int k2 = 1;
  vector<int> res2 = s.topKFrequent(nums2, k2);
  sort(res2.begin(), res2.end());
  vector<int> expected2{1};
  sort(expected2.begin(), expected2.end());
  assert(res2 == expected2);

  vector<int> nums3{4, 4, 4, 6, 6, 6, 7, 8};
  int k3 = 2;
  vector<int> res3 = s.topKFrequent(nums3, k3);
  sort(res3.begin(), res3.end());
  vector<int> expected3{4, 6};
  sort(expected3.begin(), expected3.end());
  assert(res3 == expected3);

  vector<int> nums4{-1, -1, -2, -2, -2, 3};
  int k4 = 2;
  vector<int> res4 = s.topKFrequent(nums4, k4);
  sort(res4.begin(), res4.end());
  vector<int> expected4{-2, -1};
  sort(expected4.begin(), expected4.end());
  assert(res4 == expected4);

  vector<int> nums5{5, 6, 6, 7, 7, 7, 8, 8, 8, 8};
  int k5 = 3;
  vector<int> res5 = s.topKFrequent(nums5, k5);
  sort(res5.begin(), res5.end());
  vector<int> expected5{6, 7, 8};
  sort(expected5.begin(), expected5.end());
  assert(res5 == expected5);

  return 0;
}
