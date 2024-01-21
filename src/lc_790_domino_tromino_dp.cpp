#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   private:
    int MOD = 1'000'000'007;
    unordered_map<int, long> f_dp;
    unordered_map<int, long> p_dp;

    long f(int k) {
        if (f_dp.find(k) != f_dp.end()) return f_dp.at(k);
        long val;
        if (k == 1) {
            val = 1L;
        } else if (k == 2) {
            val = 2L;
        } else {
            val = (f(k - 1) + f(k - 2) + 2 * p(k - 1)) % MOD;
        }
        f_dp.insert({k, val});
        return val;
    }

    long p(int k) {
        if (p_dp.find(k) != p_dp.end()) return p_dp.at(k);
        long val;
        if (k == 2) {
            val = 1L;
        } else {
            val = (p(k - 1) + f(k - 2)) % MOD;
        }
        p_dp.insert({k, val});
        return val;
    }

   public:
    int numTilings(int n) { return static_cast<int>(f(n)); }
};

int main() {
    Solution s;
    assert(s.numTilings(3) == 5);
    assert(s.numTilings(1) == 1);
}