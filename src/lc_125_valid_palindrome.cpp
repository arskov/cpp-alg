#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalnum((unsigned char)s[l]))
        l++;
      while (l < r && !isalnum((unsigned char)s[r]))
       r--;
      if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r]))
        return false;
      l++;
      r--;
    }
    return true;
  }
};

int main() {
  Solution s;
  bool res = s.isPalindrome("A man, a plan, a canal: Panama");
  assert(res == true);
  res = s.isPalindrome("race a car");
  assert(res == false);
  res = s.isPalindrome("");
  assert(res == true);
  res = s.isPalindrome(" ");
  assert(res == true);
  res = s.isPalindrome("0P");
  assert(res == false);
  res = s.isPalindrome("ab_a");
  assert(res == true);
  return 0;
}
