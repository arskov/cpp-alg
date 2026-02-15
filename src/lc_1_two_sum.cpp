#include <vector>
#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int complement = target - curr;
            auto candidate = lookup.find(complement);
            if (candidate != lookup.end()) {
                return {candidate->second, i};
            }
            lookup[curr] = i;
        }
        return {};
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input {1,3,2,5,3,4};
  auto result = s.twoSum(input, 7);
  vector<int> expected = {2, 3};
  assert(result == expected);
}
