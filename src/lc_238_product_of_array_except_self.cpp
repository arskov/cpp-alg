#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        long prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = (int)prefix;
            prefix *= nums[i];
        }
        long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = (int)(ans[i] * suffix);
            suffix *= nums[i];
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input {7,1,5,3,6,4};
  auto res = s.productExceptSelf(input);
  for (const auto& e : res) {
    cout << e << ",";
  }
  cout << endl;
  vector<int> expected {360,2520,504,840,420,630};
  assert(res == expected);
}
