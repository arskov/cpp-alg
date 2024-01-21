#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Palindrome After Deleting at Most One Character
 */
class Solution {
   public:
    bool validPalindrome(string arr) {
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            if (arr[i] == arr[j]) {
                i++;
                j--;
                continue;
            }
            int a = i, b = j;
            bool found = true;
            j--;
            while (i < j) {
                if (arr[i++] != arr[j--]) found = false;
            }
            if (found) return found;
            found = true;
            i = a;
            j = b;
            i++;
            while (i < j) {
                if (arr[i++] != arr[j--]) found = false;
            }
            return found;
        }

        return true;
    }
};

int main() {
    Solution s;
    string a{"madame"};
    cout << a << " = " << s.validPalindrome(a) << endl;
    string b{"dead"};
    cout << b << " = " << s.validPalindrome(b) << endl;
    string c{"abaaba"};
    cout << c << " = " << s.validPalindrome(c) << endl;
}
