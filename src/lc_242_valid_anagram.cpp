#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> lookup;
        int n = s.size();
        lookup.reserve(n);
        for (int i = 0; i < n; i++) {
            lookup[s[i]]++;
            lookup[t[i]]--;
        }
        for (const auto& [ch, i] : lookup) {
            if (i != 0) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
  Solution s;
  bool res = s.isAnagram("anagram", "nagaram");
  assert(res == true);
}
