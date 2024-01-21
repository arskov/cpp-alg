#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minEatingSpeed(vector<int> &piles, int h) {
        auto max_it = max_element(piles.begin(), piles.end());
        int b = 1;
        int e = *max_it;
        while (b < e) {
            int m = (e + b) / 2;
            int hours = calculate(piles, m);
            if (hours <= h) {
                e = m;
            } else {
                b = m + 1;
            }
        }
        return e;
    }

   private:
    int calculate(vector<int> const &nums, int k) {
        int res{0};
        for (auto v : nums) {
            res += round(ceil(static_cast<double>(v) / k));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> piles1{30, 11, 23, 4, 20};
    assert(30 == s.minEatingSpeed(piles1, 5));
    assert(23 == s.minEatingSpeed(piles1, 6));
}