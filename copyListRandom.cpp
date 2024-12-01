#include<iostream>
#include<unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
private:
void insertAtTail(Node* head, Node* tail,int d){
    Node* newNode=new Node(d);
    if(head==nullptr){
        head=tail=newNode;
        return  ;

    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
    public:
    Node* copyRandomList(Node* head) {
        //s1 clone list
        Node* cloneHead=nullptr;
        Node* cloneTail=nullptr;
        Node* temp=head;
        while(temp!=nullptr){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        //s2 map
        unordered_map<Node*,Node*>OldToNewNode;
        Node* orignalNode=head;
        Node* clonedNode=cloneHead;
        while(orignalNode!=nullptr){
            OldToNewNode[orignalNode]=clonedNode;
            orignalNode=orignalNode->next;
            clonedNode=clonedNode->next;
        }
        //s3 random pointer
        orignalNode=head;
        clonedNode=cloneHead;
        while(orignalNode!=nullptr){
            clonedNode->random=OldToNewNode[orignalNode->random];
            orignalNode=orignalNode->next;
            clonedNode=clonedNode->next;
        }
        return cloneHead;
        
    }
};