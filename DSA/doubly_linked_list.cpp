#include <iostream>
using namespace std;

class doubly_linked_list{
    public:
    int data;
    doubly_linked_list* previous;
    doubly_linked_list* next;

    doubly_linked_list(int data){
        this -> data = data;
        this -> next = NULL;
        this -> previous = NULL;
    }
};

void InsertAtTail(int new_data,doubly_linked_list* &tail){
    doubly_linked_list* temp = new doubly_linked_list(new_data);
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
}

void print(doubly_linked_list* &head){
    doubly_linked_list* temp = head;
    while (temp != NULL){
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

int main(){
    cout<<"Enter how many datas you want to enter : ";
    int x;
    cin>>x;
    int arr[x];
    cout<<"Enter the elements : ";
    for (int i = 0; i < x; i++)
    {
        cin>>arr[i];
    }

    doubly_linked_list* head = new doubly_linked_list(arr[0]);
    doubly_linked_list* tail = head;
    for (int i = 1; i < x; i++)
    {
        InsertAtTail(arr[i],tail);
    }
    print(head);
    return 0;
}