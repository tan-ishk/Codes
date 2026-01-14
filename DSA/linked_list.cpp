#include <iostream>
using namespace std;

class linked_list{
    public:
    int data;
    linked_list* next;

    linked_list(int data){
        this->data = data;
        this->next= nullptr;
    }
};

void InsertAtHead(int new_data,linked_list* &head){
    linked_list* temp = new linked_list(new_data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(int new_data,linked_list* &tail){
     linked_list* temp = new linked_list(new_data);
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
}

void Delete(int position, linked_list* &head){
    linked_list* temp = head;
    //if position at first
    if (position == 1)
    {
        head = temp->next;
        temp -> next = NULL;
        delete temp;
        return;
    }
    int i = 1;
    while (i<position-1)
    {
        temp = temp->next;
        i++;
    }
    //if position at last
    if (temp->next->next == NULL)
    {
        linked_list* to_delete = temp->next;
        temp->next = NULL;
        delete to_delete;
        return;
    }
    linked_list* to_delete = temp->next;
    temp->next = temp->next->next;
    to_delete->next = NULL;
    delete to_delete;
}

void InsertAtMiddile(int new_data,linked_list* &head,int position,linked_list* &tail){
    if (position == 1)
    {
        InsertAtHead(new_data, head);
    }
    
    else {
    linked_list* temp = head;
    int cnt = 1;
    while (cnt<position-1)
    {
        temp = temp ->next;
        cnt++;
    }
    if (temp ->next == NULL)
    {
        InsertAtTail(new_data,tail);
    }
    
    else {
    linked_list* NodeToInsert = new linked_list (new_data);
    NodeToInsert ->next = temp -> next;
    temp -> next = NodeToInsert;}
    }
}


void print(linked_list* &head){
    linked_list* temp = head;
    while (temp != NULL){
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

int main(){
    linked_list* head = new linked_list(80);
    linked_list* tail = head;

    print(head);
    InsertAtHead(50,head);
    print(head);
    InsertAtHead(20,head);
    print(head);
    InsertAtTail(110,tail);
    print(head);
    InsertAtMiddile(11,head,3,tail);
    print(head);
    InsertAtMiddile(0,head,3,tail);
    print(head);
    InsertAtMiddile(0,head,1,tail);
    print(head);
    InsertAtMiddile(0,head,8,tail);
    print(head);
    Delete(8,head);
    print(head);
    return 0;
}