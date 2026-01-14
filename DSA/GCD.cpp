#include <iostream>
using namespace std;
int findGcd(int x, int y) {
  int diff = y - x;
  int ans = 0;
  int i = 1;
  if (diff < 0) {
    diff = diff * (-1);
  }
  int ab_diff = diff;
  for (; diff > 0; diff = ab_diff / i) {
    if ((x % diff == 0) && (y % diff == 0)) {
      ans = diff;
      return ans;
    } else {
      i++;
    }
  }
  return 0;
}
int main(){
    cout<<"Enter two numbers to find GCD : ";
    int x,y;
    cin>>x>>y;
    int gcd = findGcd(x,y);
    cout<<"The GCD is : "<<gcd;
    return 0;
}