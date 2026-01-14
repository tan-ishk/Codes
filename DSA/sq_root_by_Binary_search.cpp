#include <iostream>
using namespace std;
long long int binarysearch(int n)
{
    int s = 0;
    int e = n;
    long long int m = s + ((e - s) / 2);
    long long int ans = -1;
    while (s <= e)
    {
    long long int squre = m * m;
        if (n == squre)
        {
            ans = m;
        }
        else if (n < squre)
        {
            e = m - 1;
        }
        else if (n > squre)
        {
            ans = m;
            s = m + 1;
        }
        m = s + ((e - s) / 2);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int ans = binarysearch(n);
    cout << "The squre root is : " << ans;
    return 0;
}