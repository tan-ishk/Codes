#include<iostream>
using namespace std;

class Linked_List{
    
    int data;
    Linked_List* next;
public:

    Linked_List(int x){
        this->data = x;
        this->next = NULL;
    }

    Linked_List* Include_tail(int data){
        Linked_List* head = this;
        while(head->next != NULL){
            head = head -> next;
        }
        Linked_List* temp = new Linked_List(data);
        head->next = temp;
        return this;
    }

    void Display(){
        Linked_List* temp = this;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp ->next;
        }
        
    }
};

int main(){
    Linked_List* LL = new Linked_List(0);
    LL->Include_tail(5);
    LL->Display();
}