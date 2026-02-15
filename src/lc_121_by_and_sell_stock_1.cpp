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

  vector<int> input2 {7,6,4,3,1};
  int res2 = s.maxProfit(input2);
  assert(res2 == 0);

  vector<int> input3 {1,2,3,4,5};
  int res3 = s.maxProfit(input3);
  assert(res3 == 4);

  vector<int> input4 {2,4,1};
  int res4 = s.maxProfit(input4);
  assert(res4 == 2);

  vector<int> input5 {3,3,5,0,0,3,1,4};
  int res5 = s.maxProfit(input5);
  assert(res5 == 4);

  vector<int> input6 {2};
  int res6 = s.maxProfit(input6);
  assert(res6 == 0);
}
