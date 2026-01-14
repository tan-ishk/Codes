#include<iostream>
using namespace std;

int main(){
    
    cout<<"Enter the monthly insvestment : ";
    int n;
    cin>>n; 

    cout<<"Enter the rate of return in percent (in year) : ";
    int r; 
    cin>>r;

    float total = 0;
    for (int i = 0; i < 12; i++)
    {
        // maths
        float temp = n * (1 + (r * i)/1200.0f);
        total += temp;
    }
    
    cout<<"Total money after 1 year : "<<total<<endl;
}