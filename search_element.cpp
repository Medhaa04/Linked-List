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
bool search(node* &head,int key){
    node* i=head;
    while(i != NULL){
        if(i ->data==key){
            return true;
        }
        i=i->next;
    }
    return false;

}

bool recur_search(node* &head,int key){
    //base
    node* i=head;
    if(i == NULL){
        return false;

    }
    if (i->data == key) {
        return true; // Element found
    }
    return recur_search(i->next,key);



}

int main(){
    node* head=new node(1);
    head ->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    int key=3;
    // if(search(head,3)){
    //     cout<<"Yes";
    // }
    // else{
    //     cout<<"no";
    // }
     if(recur_search(head,3)){
        cout<<"Yes";
    }
    else{
        cout<<"no";
    }
    

}