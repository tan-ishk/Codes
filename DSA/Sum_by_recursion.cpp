#include <iostream>
using namespace std;
int sum_finder(int *arr, int n){
    if(n == 1){
        return arr[0];
    }
    int current_sum = sum_finder(arr+1,n-1);
    int new_sum = current_sum + arr[0];
}
int main(){
    cout<<"Enter size of array : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array : ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int sum = sum_finder(arr,n);
    cout<<"Sum is : "<<sum;
    return 0;
}