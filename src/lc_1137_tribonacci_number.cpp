#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        switch (n)
        {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        }
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++)
        {
            int sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }
        return c;
    }
};

int main()
{
    Solution s;
    int res = s.tribonacci(4);
    assert(4 == res);
    cout << "n = 4, res = " << res << endl;

    res = s.tribonacci(25);
    assert(1389537 == res);
    cout << "n = 25, res = " << res << endl;
}