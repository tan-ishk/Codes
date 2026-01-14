#include<iostream>
using namespace std;

int main(){
    int i = 0;
    do
    {
        if (i == 34)
        {
            continue;
        }
        cout<<i<<endl;
        i++;
    }    while (i < 101);

    return 0;
}