//5th element from end of a linked list without calculating size of linked list
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
node* findfifFromlast(node* head){
    if(head==nullptr){
        return nullptr;
    }
    node* slow = head;
    node* fast = head;

    for (int i = 0; i < 5; ++i) {
        if (fast == nullptr) {
            return nullptr;  // Return nullptr if the list has less than 5 nodes
        }
        fast = fast->next;
    }
     // Move both pointers until the fast pointer reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // 5th element from the end
}
int main() {

    node* head = new node(1);
    node* current = head;
    for (int i = 2; i <= 10; ++i) {
        current->next = new node(i);
        current = current->next;
    }

    node* fifthFromEnd = findfifFromlast(head);
    if (fifthFromEnd) {
        cout << "5th element from the end: " << fifthFromEnd->data << endl;
    } else {
        cout << "Invalid." << endl;
    }
    return 0;
}

