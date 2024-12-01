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

void insertatend(node* &head,node* &tail,int data ){
    if(head==NULL){
        node *n=new node(data);           //ll is empty
        head=n;
        tail=n;
    }
    else{
        node *n= new node(data);
        tail->next=n;
        tail=n;
    }


}

void print(node *head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    node *head,*tail;
    head=tail=NULL;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
    print(head);
    return 0;
}