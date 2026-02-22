#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target)
        return {l + 1, r + 1};
      else if (sum > target)
        r--;
      else
        l++;
    }
    return {};
  }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  Solution s;
  vector<int> res = s.twoSum(numbers, target);
  assert((res == vector<int>{1, 2}));

  numbers = {2, 3, 4};
  target = 6;
  res = s.twoSum(numbers, target);
  assert((res == vector<int>{1, 3}));

  numbers = {-1, 0};
  target = -1;
  res = s.twoSum(numbers, target);
  assert((res == vector<int>{1, 2}));

  numbers = {1, 2, 3, 4, 4, 9, 56, 90};
  target = 8;
  res = s.twoSum(numbers, target);
  assert((res == vector<int>{4, 5}));
}
