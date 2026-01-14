#include <iostream>
using namespace std;
int main(){
    int arr[] = {19, 12, 16, 18, 12, 18, 22, 13, 17};
    int m;
    cin>>m;
    int size = sizeof(arr) / 4;
  int arr2[size];
  for (int i = 0; i <= m; i++) {
      arr2[i] = arr[i];
  }
  int sum = size + m;
  for (int i = m+1; i < size; i++) {
      arr2[i] = arr[sum - i];
  }
  for (int i = 0; i < size; i++) {
      arr[i] = arr2[i];
  }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}