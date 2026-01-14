#include <iostream>
#include <string>
using namespace std;

void reverse(char str[],int s,int e){
    while (s < e)
    {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
    }
}

int main(){
    cout<<"Enter a string : ";
    char str[50];
    int n = 50;
    gets(str);
    for (int i = 0; i < n; i++)
    {
        int previous_point = 0;
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse(str,previous_point,i-1);
            previous_point = i+1;
        }
    }
    cout<<"Your new string is : "<<str;
    return 0;
}