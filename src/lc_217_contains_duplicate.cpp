#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.size() < 2)
      return false;
    unordered_set<int> seen;
    seen.reserve(nums.size());
    for (auto num : nums) {
      if (seen.find(num) != seen.end())
        return true;
      seen.insert(num);
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> input{1, 2, 3, 4, 5, 6, 0, 9, 8, 2};
  bool res = s.containsDuplicate(input);
  assert(res == true);
}
