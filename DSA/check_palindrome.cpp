#include <bits/stdc++.h>
using namespace std;
bool RemoveFuckers(char s)
{
    if (((s <= 'Z') && (s >= 'A')) || ((s <= 'z') && (s >= 'a')) || ((s <= '9') && (s >= '0')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char LowerCase(char s)
{
    if ((s <= 'Z') && (s >= 'A'))
    {
        char temp = s - 'A' + 'a';
        return temp;
    }
    else if (((s <= 'z') && (s >= 'a')) || ((s <= '9') && (s >= '0')))
    {
        return s;
    }
}
bool checkPalindrome(string s)
{
    int n = s.size();
    string fuck = "";
    for (int i = 0; i < n; i++)
    {
        if (RemoveFuckers(s[i]))
        {
            fuck.push_back(s[i]);
        }
    }
    cout << "After removing special char : " << fuck;
    int size = fuck.size();
    for (int i = 0; i < size; i++)
    {
        fuck[i] = LowerCase(fuck[i]);
    }
    cout << "\nAfter lower case : " << fuck << "\n";
    for (int i = 0; i < size / 2; i++)
    {
        if (fuck[i] != fuck[size - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cout << "Enter the string : ";
    string fuck;
    getline(cin, fuck);
    if (checkPalindrome(fuck))
    {
        cout << "your string is a palindrome.";
    }
    else
    {
        cout << "your string is not a palindrome.";
    }
}