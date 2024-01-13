#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        auto cmp = [](pair<int, int> const &a, pair<int, int> const &b)
        {
            return a.second > b.second;
        };
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < nums1.size(); i++)
        {
            sorted_nums.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(sorted_nums.begin(), sorted_nums.end(), cmp);
        vector<int> hp;
        long long top_k_sum{0};
        for (int i = 0; i < k; i++)
        {
            auto elem = sorted_nums[i];
            top_k_sum += elem.first;
            hp.push_back(elem.first);
        }
        auto hp_cmp = greater<int>();
        make_heap(hp.begin(), hp.end(), hp_cmp);
        long long ans = top_k_sum * sorted_nums[k - 1].second;
        for (int i = k; i < nums1.size(); i++)
        {
            pop_heap(hp.begin(), hp.end(), hp_cmp);
            int hp_min = hp.back();
            hp.pop_back();
            top_k_sum -= hp_min;
            auto elem = sorted_nums[i];
            top_k_sum += elem.first;
            ans = std::max(ans, top_k_sum * elem.second);
            hp.push_back(elem.first);
            push_heap(hp.begin(), hp.end(), hp_cmp);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums1{1, 3, 3, 2};
    vector<int> nums2{2, 1, 3, 4};
    int k1{3};
    long long res1 = s.maxScore(nums1, nums2, k1);
    assert(res1 == 12);
    cout << "Result: " << res1 << endl;

    vector<int> nums3{4, 2, 3, 1, 1};
    vector<int> nums4{7, 5, 10, 9, 6};
    int k2{1};
    long long res2 = s.maxScore(nums3, nums4, k2);
    assert(res2 == 30);
    cout << "Result: " << res2 << endl;

    vector<int> nums5{2, 1, 14, 12};
    vector<int> nums6{11, 7, 13, 6};
    int k3{3};
    long long res3 = s.maxScore(nums5, nums6, k3);
    assert(res3 == 168);
    cout << "Result: " << res3 << endl;
}