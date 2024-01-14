#include <iostream>
#include <cassert>

const int GUESS_ME_NUMBER = 7;
const int MAX_RANGE = 20;

int guess(int num)
{
    if (num == GUESS_ME_NUMBER)
    {
        return 0;
    }
    else if (num > GUESS_ME_NUMBER)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int begin = 0;
        int end = n;
        while (begin < end)
        {
            int mid = begin + (end - begin) / 2;
            int res = guess(mid);
            if (res < 0)
            {
                end = mid - 1;
            }
            else if (res > 0)
            {
                begin = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return end;
    }
};

int main()
{
    Solution s;
    int res = s.guessNumber(MAX_RANGE);
    assert(res == GUESS_ME_NUMBER);
}