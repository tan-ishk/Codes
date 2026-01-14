#include <iostream>
#include <vector>
using namespace std;
int SumLeft(int arr[], int index, int size)
{
    int sum = 0;
    for (int i = 0; i < index; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int SumRight(int arr[], int index, int size)
{
    int sum = 0;
    for (int i = size-1; i > index; i--)
    {
        sum += arr[i];
    }
    return sum;
}
int pivotIndex(int nums[],int size) {
    int l = size;
    int s = 0;
    int e = l-1;
    int m = s+(e-s)/2;
    int ans = -1;
    while (s<=e) {
        int sum1 = SumLeft(nums, m, l);
        int sum2 = SumRight(nums, m, l);
    if(sum1 == sum2){
        ans = m;
        return ans;
    }
    else if(sum1 > sum2){
        e = m-1;
    }
    if(sum1 < sum2){
        s = m+1;
    }
    m = s+(e-s)/2;
    }
    return ans;
}
int main(){
    cout<<"Enter size of array : ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans = pivotIndex(arr,size);
    cout<<"Your pivot element is : "<<ans;
    return 0;
}