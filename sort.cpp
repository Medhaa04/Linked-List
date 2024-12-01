#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//brute
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
        for(int i=0;i<arr.size();++i){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;
        
    }
};

//optimised;
class SolOptimal{
    public:
     
    ListNode* sortLL(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        // ListNode* temp=head;
        ListNode* middleele=middle(head);
        ListNode* right=middleele->next;
        middleele->next=nullptr;
        ListNode*left=head;
        left=sortLL(left);
        right=sortLL(right);
        return mergeSort(left,right);




        

    }
};