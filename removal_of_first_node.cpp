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
void removeFirstNode(node*& head,node* &tail) {
    if (head == nullptr) {
    
        return;
    }
    else if(head==tail){
        node* temp=head;
        delete temp;
        head=tail=NULL;

    }
    else{
    node* temp = head;
    head = head->next;     //head points to next
    delete temp;
    temp=NULL;
    }
}

int main(){
    node* tail;
    node* head= new node(1);
    head -> next=new node(2);
    head ->next ->next=new node(3);
    //orignal ll
    
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout <<endl;

    removeFirstNode(head,tail);

    //after
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;




}