#include <iostream>
#include <vector>
using namespace std;

bool is_valid(vector<int> &nums, int a, int b)
{
    if (a == b)
        return false;
    if ((nums[a] > 0 && nums[b] < 0) || (nums[a] < 0 && nums[b] > 0))
        return false;
    return true;
}

int next(vector<int> &nums, int idx)
{
    int arr_size = nums.size();
    int next = (idx + nums[idx]) % arr_size;
    if (next < 0)
        next = arr_size + next;
    return next;
}

class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int arr_size = static_cast<int>(nums.size());
        if (arr_size == 0)
            return false;
        for (int i = 0; i < arr_size; i++)
        {
            int slow = i;
            int fast = i;
            while (true)
            {
                int next_slow = next(nums, slow);
                if (!is_valid(nums, next_slow, slow))
                    break;
                int next_fast = next(nums, fast);
                if (!is_valid(nums, next_fast, fast))
                    break;
                fast = next_fast;
                next_fast = next(nums, fast);
                if (!is_valid(nums, next_fast, fast))
                    break;
                if (next_slow == next_fast)
                    return true;
                slow = next_slow;
                fast = next_fast;
            }
        }
        return false;
    }

private:
    inline bool is_valid(vector<int> &nums, int a, int b)
    {
        if (a == b)
            return false;
        if ((nums[a] > 0 && nums[b] < 0) || (nums[a] < 0 && nums[b] > 0))
            return false;
        return true;
    }

    inline int next(vector<int> &nums, int idx)
    {
        int arr_size = nums.size();
        int next = (idx + nums[idx]) % arr_size;
        if (next < 0)
            next = arr_size + next;
        return next;
    }
};

int main()
{
    Solution s;
    vector<int> in1{2, -1, 1, -2, -2};
    bool res = s.circularArrayLoop(in1);
    cout << "Result: " << res << endl;
}