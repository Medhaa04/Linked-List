// implement
// insertion
// deletion
// searching
// reverse
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node (int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int d){
    node* n=new node(d);
    n->next=head;
    head->prev=n;
    head=n;

}

void insertAtEnd(node* &tail,int d){
    node* n=new node(d);
    tail->next=n;
    n->prev=tail;
    tail=n;

};
void insert(node* &head,node* &tail,int d,int index){
    if(index==0){
        insertAtHead(head,d);
    }
    node* temp=head;
    int cnt=1;
    while(cnt<index-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtEnd(tail,d);
        return;
    }

    node* nodeTBI=new node(d);
    nodeTBI->next=temp->next;
    temp->next->prev=nodeTBI->next;
    temp->next=nodeTBI;
    nodeTBI->prev=temp;

}

void deletefirst(node* &head){
    node* temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}

void deleteany(node* &head,int index){
    node* curr=head;
    node* prev=NULL;
    int ct=1;
    while(ct<index){
        prev=curr;
        curr=curr->next;
        ct++;
    }
    
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

void print(node* head){ 
        while(head !=NULL){
            cout<<head ->data<<" ";
            head=head ->next;
        }
        cout<<endl;
    

}

//get lenght

int main(){
    node* node1=new node(1);
    node* head=node1;
    node* tail=node1;

    print(head);

    insertAtHead(head,2);
    print(head);

    insertAtEnd(tail,3);
    print(head);

    insert(head,tail,9,2);
    print(head);


return 0;
}