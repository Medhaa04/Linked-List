#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
Node* removeKthNode(Node* head, int K)
{
if (head == nullptr || K <= 0) {
        return nullptr; // Invalid input
    }

    int length = 0;
    Node* temp = head;

    // Count the number of nodes in the list
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // If K is greater than the length of the list, return nullptr
    if (K > length) {
        return nullptr;
    }

    // If K is equal to the length of the list, remove the head node
    if (K == length) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Find the (n - k)th node from the beginning
    temp = head;
    for (int i = 0; i < length - K - 1; ++i) {
        temp = temp->next;
    }

    // Remove the Kth node
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}