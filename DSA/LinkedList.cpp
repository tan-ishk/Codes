#include<iostream>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList* next = nullptr;

    LinkedList(int element){
        data = element;
    }

    void AddElement(int element,LinkedList* l){
        LinkedList* newNode = new LinkedList(element);
        LinkedList* temp = l;
        temp -> next = newNode;
        temp = temp -> next;
    }

    void DisplayElements(LinkedList* l){
        while (l != nullptr)
        {
            cout<<l->data<<" ";
            l = l -> next;
        }
        
    }
};
int main(){
    LinkedList l(10);
    l.AddElement(40, l);
    l.DisplayElements(l);
}