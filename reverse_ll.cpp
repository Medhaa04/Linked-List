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
node* reverse(node* head){
    /*node* prev=nullptr;
    node*current=head;
    node* next=nullptr;

    while(current != nullptr){
        next=current->next;
        current->next=prev;
    
    prev=current;
    current=next;
    }
    return prev;*/
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;

    while(curr !=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
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
    head->next->next->next->next = new node(5);

    cout << "Original: ";
    printLinkedList(head);

    node* reversedHead = reverse(head);

    cout << "Reversed: ";
    printLinkedList(reversedHead);

    

    return 0;
}
/*
recursive
if (head == NULL || head->next == NULL) {
        return head;
    }
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    Node* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following
    // the current 'head' node.
    Node* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;

*/





