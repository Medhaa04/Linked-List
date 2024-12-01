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
    while(head != NULL){
        ct++;
        head=head->next;
    }
    return ct;
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

void insert(node* &tail,node* &head,int d,int index){
    node* n=new node(d);
    if(index==0){
        insertatbeginning(head,tail,d);
        return;
        
    }
    else if(index==sizeofLL(head)){
        insertatend(head,tail,d);
    }
    else{
        node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp -> next;
        }
        //  node*bm=temp->next;
        node* n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }

}


void print(node *head){
    while(head !=NULL){
        cout<<head ->data<<" ";
        head=head ->next;
    }
    cout<<endl;
}

int main(){
    node* head,*tail;
    head=tail=NULL;
    insert(head,tail,2,0);
    

return 0;
}


