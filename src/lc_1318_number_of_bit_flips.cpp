#include <cassert>

class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int tmp = a | b;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            int k = (tmp >> i) & 1;
            int v = (c >> i) & 1;
            if (v == 1 && k == 0) {
                count += 1;
            } else if (v == 0 && k == 1) {
                if ((a >> i & 1) == 1) count += 1;
                if ((b >> i & 1) == 1) count += 1;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    assert(s.minFlips(2, 6, 5) == 3);
    assert(s.minFlips(4, 2, 7) == 1);
    assert(s.minFlips(1, 2, 3) == 0);
}