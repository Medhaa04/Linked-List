#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    // bool isCyclic(ListNode*head){
    //     unordered_map<ListNode*,bool>visited;
    //     if(head==nullptr) return false;
    //     ListNode* temp=head;
    //     while(temp!=nullptr){
    //         if(visited[temp]==true){
    //             return true;
    //         }
    //         visited[temp]=true;
    //         temp=temp->next;
    //     }
    //     return false;
    // }
    // ListNode *detectCycle(ListNode *head) {
    //         ListNode*slow=head;
    //         ListNode*fast=head;

    //         while(fast!=nullptr){
    //             fast=fast->next;
    //             if(fast!=nullptr){
    //                 fast=fast->next;
    //             }
    //             slow=slow->next;
    //             if(fast==slow){
    //                 slow=head;
    //                 slow=slow->next;                                     //identifying starting point of loop
    //                 fast=fast->next;
    //                 if(slow==fast)
    //                     return slow;
                    
    //             }
    //             else return NULL;
    //         }
        

    // } 

    bool isCyclic(ListNode* head){
        if(head==nullptr){
            return true;
        }
        unordered_map<ListNode*,bool>visited;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(visited[temp]=true) return true;
            visited[temp]=true;
            temp=temp->next;
        }
        return false;

    } 
    ListNode* detectCycle(ListNode* head){
        if(head==nullptr) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr){
            fast=fast->next;
            while(fast!=nullptr){
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow){
                slow=head;
                slow=slow->next;
                fast=fast->next;
                if(slow==fast) return slow;
            }
            else return NULL;   
        }
    }
    
};