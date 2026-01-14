#include <iostream>
// #include <cmath>
// this code is for probably root n complexity we have to do it in log n;
using namespace std;
int floorSqrt(int n)
{
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    int s = 0;
    int e = n-1;
    int m = s + ((e-s)/2);
    int ans = 0;
    while(s<=e){
        if ((n == 1)||(n == 2)){
            return 1;
        }
        else if (n == 0){
            return 0;
        }
        else if((arr[m]*arr[m] <= n) && (arr[m+1]*arr[m+1] > n)){
            ans = m;
            return ans;
        }
        else if (arr[m]*arr[m] > n){
            e = m - 1;
        }
        else if (arr[m]*arr[m] < n){
            s = m + 1;
        }
        m = s + ((e-s)/2);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int ans = floorSqrt(n);
    cout<<"The squre root is : "<<ans;
    return 0;
}