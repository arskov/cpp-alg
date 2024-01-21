#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        auto left_end = min(costs.begin() + candidates, costs.end());
        priority_queue<int, vector<int>, greater<int>> pq_left(costs.begin(), left_end);
        auto right_begin = max(costs.end() - candidates, left_end);
        priority_queue<int, vector<int>, greater<int>> pq_right(right_begin, costs.end());
        long long total{0};
        for (int i = 0; i < k; i++) {
            if ((pq_right.empty() && !pq_left.empty()) ||
                (!pq_left.empty() && !pq_right.empty() && pq_left.top() <= pq_right.top())) {
                total += pq_left.top();
                pq_left.pop();
                if (left_end < right_begin) {
                    pq_left.push(*left_end);
                    left_end++;
                }
            } else if ((pq_left.empty() && !pq_right.empty()) ||
                       (!pq_left.empty() && !pq_right.empty() && pq_left.top() > pq_right.top())) {
                total += pq_right.top();
                pq_right.pop();
                if (left_end < right_begin) {
                    pq_right.push(*(right_begin - 1));
                    right_begin--;
                }
            }
        }
        return total;
    }
};

int main() {
    Solution s;

    vector<int> costs1{57, 33, 26, 76, 14, 67, 24, 90, 72, 37, 30};
    long long res = s.totalCost(costs1, 11, 2);
    assert(526 == res);
    cout << res << endl;

    vector<int> costs2{17, 12, 10, 2, 7, 2, 11, 20, 8};
    res = s.totalCost(costs2, 3, 4);
    assert(11 == res);
    cout << res << endl;

    vector<int> costs3{1, 2, 4, 1};
    res = s.totalCost(costs3, 3, 3);
    assert(4 == res);
    cout << res << endl;

    vector<int> costs4{31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58};
    res = s.totalCost(costs4, 11, 2);
    assert(423 == res);
    cout << res << endl;
}