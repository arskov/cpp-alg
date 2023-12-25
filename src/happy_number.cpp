#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = sumOfSquares(n);
        int fast = sumOfSquares(sumOfSquares(n));
        while (true) {
            if (fast == 1) return true;
            if (slow == fast) return false;
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return false;
    }
private:
    int sumOfSquares(int n) {
        int sum{0};
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << "1 is happy -> " << s.isHappy(1) << endl;
    cout << "2 is happy -> " << s.isHappy(2) << endl;
    cout << "3 is happy -> " << s.isHappy(3) << endl;
    cout << "4 is happy -> " << s.isHappy(4) << endl;
    cout << "8 is happy -> " << s.isHappy(8) << endl;
    cout << "19 is happy -> " << s.isHappy(19) << endl;
    cout << "2147483646 is happy -> " << s.isHappy(2147483646) << endl;
}