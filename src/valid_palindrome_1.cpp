#include <string>
#include <iostream>

using namespace std;

bool validPalindrome(string arr)
{
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
            continue;
        }
        int a = i, b = j;
        bool found = true;
        j--;
        while (i < j)
        {
            if (arr[i++] != arr[j--])
                found = false;
        }
        if (found)
            return found;
        found = true;
        i = a;
        j = b;
        i++;
        while (i < j)
        {
            if (arr[i++] != arr[j--])
                found = false;
        }
        return found;
    }

    return true;
}

int main()
{
    string a{"madame"};
    cout << a << " = " << validPalindrome(a) << endl;
    string b{"dead"};
    cout << b << " = " << validPalindrome(b) << endl;
    string c{"abaaba"};
    cout << c << " = " << validPalindrome(c) << endl;
}