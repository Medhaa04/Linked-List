#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    node*nextr;
    int data;
    node (int d){
        data=d;
        left=right=NULL;
        nextr=NULL;
    }
};
int countNode(node* root){
    if(root==nullptr) return 0;
    return countNode(root->left)+countNode(root->right);
}
int height(node* root){
    if(root==nullptr) return 0;
    return max(height(root->left),height(root->right))+1;
}
int diameter(node* root){
    if(root==nullptr) return 0;


    int op1=height(root);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
void mirror(node* root){
    if(root ==nullptr) return ;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}
bool isLeaf(node* root){
    return !root->left and !root->right;
}
void leftBound(node* root,vector<int>res){
    node* curr=root->left;
    if(!isLeaf(curr)) res.push_back(curr->data);
    if(curr->left) curr=curr->left;
    else curr=curr->right;

}
void rightBound(node* root,vector<int>res){
    vector<int>ans;
    node* curr=root->right;
    if(!isLeaf(curr)) ans.push_back(curr->data);
    if(curr->right) curr=curr->right;
    else curr=curr->left;
    for(int i=ans.size();i>=0;--i) res.push_back(ans[i]);

}
void leafNode( node* root,vector<int>res){

    if(isLeaf(root)) res.push_back(root->data);
    if(root->left) leafNode(root->left,res);
    if(root->right) leafNode(root->right,res);
}
vector<int>boundary(node* root){
    vector<int>res;
    if(root==nullptr) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    leftBound(root,res);
    leafNode(root,res);
    rightBound(root,res);
    return res;

}
void levelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* frt=q.front();
        q.pop();

        if(frt==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<frt->data;
            if(frt->left) q.push(frt->left);
            if(frt->right) q.push(frt->right);
        }
    }
}
void connect(node* root){
    if(root==nullptr) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        node* prev=NULL;
        while(size--){
            node* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(prev!=NULL){
                prev->nextr=temp;
                prev=temp;
            }
        }
    }
}