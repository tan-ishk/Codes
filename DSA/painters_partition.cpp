#include<iostream>
#include<vector>
using namespace std;
bool lowestTime(int boards[], int k, int size, int mid) {
  int NumberOfPainters = 1;
  int totalArea = 0;
  for (int i = 0; i < size; i++) {
    if (totalArea + boards[i] <= mid) {
      totalArea += boards[i];
    } else {
      NumberOfPainters++;
      if ((NumberOfPainters > k) || (totalArea > mid)) {
        return false;
      }
      totalArea = boards[i];
    }
  }
  return true;
}
int findLargestMinDistance(int boards[], int k) {
  int sum = 0;
  int ans = -1;
  int size = 8;
  int start = 0;
  for (int i = 0; i < size; i++) {
    sum = sum + boards[i];
  }
  int end = sum;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (lowestTime(boards, k, size, mid)) {
      ans = mid;
      cout<<ans;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}
int maim(){
    int boards[]={6,5,6,10,9,2,3,5};
    int k = 2;
    int ans = findLargestMinDistance(boards,k);
    cout<<ans<<" ";
    return 0;
}