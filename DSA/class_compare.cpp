#include<iostream>
#include<queue>
#include<string>
using namespace std;

class student{
public :
    string name;
    int roll;
    int score;

    student(string name, int roll, int score){

        this->name = name;
        this->roll = roll;
        this->score = score;
    }
};

class compare{

    public :
    bool operator()(student A, student B){

        return A.name < B.name;
    }
};

int main(){

    student S[8] = {{"Tanishq", 24, 94}, {"Shabnam", 21, 87}, {"Jyoti", 20, 92}, {"Sakshi", 32, 84}, {"Sonam", 11, 68}, {"Neha", 19, 82}, {"Gracie", 23, 83}, {"Sabrina", 25, 70}};

    priority_queue<student, vector<student>, compare>P;

    for(int i = 0; i < 8; i++){

        P.push(S[i]);
    }

    int i = 1;
    while (!P.empty())
    {
        student temp = P.top();
        P.pop();

        cout<<i<<" : "<<temp.name<< ", roll : "<< temp.roll<< ", score : "<< temp.score<<endl;
        i++;
    }
 
    return 0;
}
