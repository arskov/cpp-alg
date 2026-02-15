#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return n;
    unordered_set<int> lookup(nums.begin(), nums.end());
    int best = 0;
    for (int x : lookup) {
      if (lookup.find(x - 1) != lookup.end())
        continue;
      int y = x;
      while (lookup.find(y) != lookup.end())
        y++;
      best = std::max(best, y - x);
    }
    return best;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> input1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int res = s.longestConsecutive(input1);
  assert(res == 9);
}
