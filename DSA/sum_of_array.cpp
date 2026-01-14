#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m) {
  int sum1 = 0;
  int sum2 = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum1 = sum1 + pow(10, n - 1 - i) * a[i];
  }
  for (int i = m - 1; i >= 0; i--) {
    sum2 = sum2 + pow(10, n - 1 - i) * b[i];
  }
  int sum = sum1 + sum2;
  int remainder = 0;
  int count = 0;
  while (sum > 0) {
    sum = sum / 10;
    count++;
  }
  vector<int> c(count);
  for (int i = 0; i<count, sum> 0; i++) {
    remainder = sum % 10;
    c[count - 1 - i] = remainder;
    sum = sum / 10;
  }
  return c;
}

int main(){
  cout<<"Enter the size of first array : ";
  int n;
  cin>>n;
  cout<<"Enter the elements of array : ";
  vector<int> a(n,0);
  for (int i = 0; i < n; i++){
    cin>>a[i];
  }
  cout<<"Enter the size of second array : ";
  int m;
  cin>>m;
  cout<<"Enter the elements of array : ";
  vector<int> b(m,0);
  for (int i = 0; i < m; i++){
    cin>>b[i];
  }
  
  vector<int> sum = findArraySum(a, n, b, m);

  cout<<"Printing Sum..."<<endl;
  for (int i = 0; i < sum.size(); i++)
  {
    cout<<sum[i];
  }
  
}