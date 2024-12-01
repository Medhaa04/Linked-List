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

    removeLastNode(head,tail);

    //after
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
return 0;



}