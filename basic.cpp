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

int main(){
    
    node a(1);
    node b(2);
    node c(3);
    a.next=&b;
    b.next=&c;
    cout<<"a is "<<a.data<<endl;
    cout<<"b is "<<(*(a.next)).data<<endl;
    cout<<"c is "<<(*((*(a.next)).next)).data<<endl;
    cout<<a.data<<" "<<a.next->data<<" "<<a.next->next->data;


    return 0;
}