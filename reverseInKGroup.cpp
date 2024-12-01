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
node* kReverse(node* head,int k){
    //base
    if(head==NULL ){
        return NULL;
    }
    //recurisve
    //s1
    node* prev=NULL;
    node* fwd=NULL;
    node* curr=head;
    int count=0;

    while(curr !=NULL && count<k){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
        count++;
    }
    //s2
    if(fwd !=NULL){
        head->next=kReverse(fwd,k);
    }
    //s3
    return prev;
}

void printLinkedList(node* head) {
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    
    head->next->next->next->next = new node(5);head->next->next->next->next->next = new node(6);
    int k;
    cout<<"ENter k:"<<endl;
    cin>>k;

    cout << "Original: ";
    printLinkedList(head);

    node* reversedHead = kReverse(head,k);

    cout << "Reversed: ";
    printLinkedList(reversedHead);

    

    return 0;
}
