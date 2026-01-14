#include <iostream>
using namespace std;
int GetPivot(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int m = s + ((e-s)/2);
    while (s<e){
        if(arr[m]>=arr[0]){
            s = m+1;
        } 
        else{
            e = m;
        }
        m = s + ((e-s)/2);
    }
    return s;
}
int binarySearch(int arr[], int key, int start, int end){
    int s = start;
    int e = end;
    int m = s + ((e-s)/2);
    int ans = -1;
    while (s<=e){
        if (arr[m] == key){
            ans = m;
            return ans;
        }
        else if (arr[m] > key){
            e  = m-1;
        } else if (arr[m] < key) {
            s = m + 1;
        }
        m = s + ((e - s) / 2);
    }
        return ans;
}
int search(int arr[], int n, int k)
{
    int ans = -1;
    int pivot = GetPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1]){
        ans = binarySearch(arr, k, pivot,n-1);
    }
    else {ans = binarySearch(arr, k, 0, pivot -1);}
    return ans;
}

int main(){
    
    return 0;
}