#include<iostream>
#include<unordered_set>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
node* intersectBrute(node* head1,node*head2){
    node* temp=head1;
    while(head2!=NULL){
        while(temp!=NULL){
        if(temp==head2){
            return head2;
        }
        temp=temp->next;

    }
    head2=head2->next;
    }
    return NULL;

}
node* intesectBetter(node* head1,node*head2){
    unordered_set<node*>st;
    while(head1!=NULL){
        st.insert(head1);
        head1=head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2) !=st.end()) return head2;
    }
    return NULL;


}
int getDifference(node* head1,node* head2){
    int len1=0,len2=0;
    while(head1!=NULL or head2!=NULL){
        if(head1!=NULL){
            len1++;
            head1=head1->next;
        }
        if(head2!=NULL){
            len2++;
            head2=head2->next;
        }
    }
    return len1-len2;
}
node* intersectOptimal(node* head1, node*head2){
    int diff=getDifference(head1,head2);
    if(diff<0){
        while(diff++!=0){
            head2=head2->next;
        }

    }
    else{
        while(diff--!=0){
            head1=head1->next;
        }
    }
    while(head1!=NULL){
        if(head1==head2) return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return head1;

}