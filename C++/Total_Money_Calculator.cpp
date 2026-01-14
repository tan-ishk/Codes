#include<iostream>
using namespace std;

// The money form previous year which increases at fix rate
float FixReturn(float n, float r){

    return n * ((100.0 + r) / 100.0);
}

// the money invested monthly
float Total_Money_From_Monthly_Investments(float n, float r){

    float total = 0;
    for (int i = 0; i < 12; i++)
    {
        // maths
        float temp = n * (1 + (r * i)/1200);
        total += temp;
    }

    return total;
}

float Total(float n, float monthly, float r){

    return (FixReturn(n, r) + Total_Money_From_Monthly_Investments(monthly, r));
}

int main(){

cout<<"Enter the amount you can invest monthly : ";
float n;
cin>>n; 

cout<<"Enter the duration in years : ";
int t; 
cin>>t;

cout<<"Enter avg rate of return yearly : ";
float r;
cin>>r;

cout<<"Enter yearly salary increment in percentage : ";
float inc;
cin>>inc;

float money = 0;
for (int i = 0; i < t; i++)
{
    // the monthly salary is n in the first year
    if(i == 0){
        money = Total(money, n, r);
    }

    // after 1 year, salary hike will take place : 
    else{
        n = n * ((100.0 + inc) / 100.0);
        money = Total(money , n, r);
    }
}
    cout<<"Your total money after "<<t<<" years is : "<<money;
}