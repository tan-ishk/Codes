#include<iostream>
using namespace std;

class Stack
{
    public:
        int data;
        int top;
        int size;
        int* arr;

        Stack(int size){
            this -> size = size;
            top = -1;
            arr = new int[size];
        }

        void pop(){
            if (top == -1)
            {
                cout<<"\nStack underflow, cant pop...\n";
                return;
            }
            top--;
        }

        bool isEmpty(){
            return (top == -1);
        }

        void push(int element){
            if(size - top > 1){
                arr[++top] = element;
                return;
            }
            cout<<"Stack overflow, cant push more !\n";
        }

        int peak(){
            if (top == -1)
            {
                cout<<"\nStack underflow, cant peak...\n";
                return -1;
            }
            return arr[top];
        }

        void Display(){
            if (top == -1)
            {
                cout<<"\nStack underflow, cant display...\n";
            }
            for (int i = 0; i <= top; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
};
int main(){
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(-3);
    s.push(0);
    s.push(10);

    s.Display();

    s.push(10);

    s.Display();

    s.pop();
    s.pop();

    s.push(5000);
    s.Display();

    cout<<s.peak();

}
