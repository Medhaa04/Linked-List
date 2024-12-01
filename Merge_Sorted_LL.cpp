#include<iostream>
using namespace std;
template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
class Solution {

public:
    Node<int>* mergeTwoLists(Node<int>* l1,Node<int>* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->data > l2->data) swap(l1,l2);

        // act as head of resultant merged list
        Node<int>* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            Node<int>* temp = NULL;

            while(l1 != NULL && l1->data <= l2->data) {

                temp = l1;//storing last sorted node  
                l1 = l1->next; 
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            swap(l1,l2);
        }

        return res;
    }
};
