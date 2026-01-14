#include <iostream>
using namespace std;

void string_reversal(string & name, int i, int j){
    if (i>j){
        return;
    }
    swap(name[i],name[j]);
    i++;
    j--;

    string_reversal(name, i, j);
}

int main(){
    cout<<"Enter a string : ";
    string name;
    getline(cin,name);
    int size = name.length()-1;
    string_reversal(name,0,size);
    cout<<"Reverse string is : "<<name<<endl;
    cout<<"sizeof(name) is : "<<sizeof(name)<<endl;
    cout<<"name.length() is : "<<size;
    return 0;
}