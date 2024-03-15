#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.empty() && t.empty()) return true;
        if (t.empty()) return false;
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size(); i++, j++) {
            while (j < t.size() && s[i] != t[j]) j++;
            if (j == t.size()) return false;
        }
        return i == s.size();
    }
};

int main() {
    Solution s;
    bool res1 = s.isSubsequence("abc", "ahbgdc");
    assert(res1 == true);
    bool res2 = s.isSubsequence("axc", "ahbgdc");
    assert(res2 == false);
    bool res3 = s.isSubsequence("aaaaaa", "bbaaaa");
    assert(res3 == false);
}