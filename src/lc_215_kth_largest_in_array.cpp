#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief Kth Largest Element in an Array
 */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // priority_queue<int> pq(nums.begin(), nums.end());
        // for (int i = 0; i < k - 1; i++) {
        //     pq.pop();
        // }
        // return pq.top();
        auto [min, max] = minmax_element(nums.begin(), nums.end());
        int size = *max - *min + 1;
        vector<int> kk(size);
        for (int n : nums)
            kk[n - *min]++;
        vector<int> res(nums.size());
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            for (int l = 0; l < kk[i]; l++)
            {
                res[j++] = i + *min;
            }
        }
        int out = res[nums.size() - k];
        return out;
    }
};

int main()
{
    Solution s;

    vector<int> test1{3, 2, 1, 5, 6, 4};
    cout << "Result: " << s.findKthLargest(test1, 2) << ", Expected:" << 5 << endl;

    vector<int> test2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "Result: " << s.findKthLargest(test2, 4) << ", Expected:" << 4 << endl;
}