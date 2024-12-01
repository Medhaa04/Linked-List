#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

node* middle(node* &head){

    // if(head==nullptr || head->next==nullptr){
    //     return head;
    // }
    node*slow=head;
    node* fast=head;
    while(fast !=nullptr && fast->next !=nullptr){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    node* mid= middle(head);
    cout << "Middle: " << mid->data << endl;

  
    return 0;
}





