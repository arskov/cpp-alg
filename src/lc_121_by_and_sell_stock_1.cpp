#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = INT_MAX;
        int max_profit = 0;
        for (auto price : prices) {
            min_price = std::min(min_price, price);
            int profit = price - min_price;
            max_profit = std::max(max_profit, profit);
        }
        return max_profit;
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input {7,1,5,3,6,4};
  int res = s.maxProfit(input);
  assert(res == 5);
}
