#include <string>
#include <iostream>

using namespace std;

string ReverseWords(string sentence)
{
    int i{0}, j{static_cast<int>(sentence.size()) - 1};
    while (i < j)
    {
        swap(sentence[i++], sentence[j--]);
    }
    i = 0;
    j = 0;
    while (j < sentence.size())
    {
        while (j < sentence.size() && sentence[j] != ' ')
            j++;
        int n = j + 1;
        j--;
        while (i < j - 1)
            swap(sentence[i++], sentence[j--]);
        i = n;
        j = n;
    }

    return sentence;
}

int main()
{
    string a{"one two three"};
    auto res = ReverseWords(a);
    cout << res << endl;
    return 0;
}