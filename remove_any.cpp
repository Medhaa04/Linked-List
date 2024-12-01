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

int sizeofLL(node* head){
    int ct=0;
    node* temp=head;
    while(head != NULL){
        ct++;
        head=head->next;
    }
    return ct;
}

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

void removeLastNode(node* &head,node* &tail){
    if(head==NULL){
        return;
    }

    else if(head ==tail){
        delete head;
        head=tail=NULL;
    }

    else{
         node* current=head;
        while(current ->next !=tail){
            current=current ->next;
        }
           current ->next=tail;
            delete tail;
            tail=current;
        }
}

void remove(node* &head,node* &tail,int index){
    if(index==0){
        removeFirstNode(head,tail);
    }

    else if(index<sizeofLL(head)){
         node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp -> next;
        }
        node* curr=temp->next;
        node* n=curr->next;
        temp ->next=n;
        delete curr;
    }
    
}

    void insertatbeginning(node* &head,node* &tail,int data){
        if(head==NULL){
            node *n=new node(data);
            head=n;
            tail=n;
        }
        else{
            node *n= new node(data);
            n->next=head;
            head=n;
        }
    }

    void print(node *head){
        while(head !=NULL){
            cout<<head ->data<<" ";
            head=head ->next;
        }
        cout<<endl;
    }

    void printll(node *head){
        while(head !=NULL){
            cout<<head ->data<<" ";
            head=head ->next;
        }
        cout<<endl;
    }
    

int main(){
    node* tail,*head;
    head=tail=NULL;
    insertatbeginning(head,tail,1);
    insertatbeginning(head,tail,2);
    insertatbeginning(head,tail,3);
    insertatbeginning(head,tail,4);
    insertatbeginning(head,tail,5);
    remove(head,tail,3);
    printll(head);
    return 0;


    


}