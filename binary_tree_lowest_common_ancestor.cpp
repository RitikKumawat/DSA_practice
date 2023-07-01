#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
          data = val;
          left=NULL;
          right=NULL;
          }
};

node* lca(node* root, int n1, int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    
    node* leftans=lca(root->left,n1,n2);
    node* rightans=lca(root->right,n1,n2);

    if(leftans!=NULL && rightans!=NULL)
        return root;
    else if(leftans==NULL && rightans!=NULL)
        return rightans;
    else if(leftans!=NULL && rightans==NULL)
        return leftans;
    else
        return NULL;
}

int main(){

node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->right = new node(20);
root->right->left->left = new node(6);

node* ans = lca(root,6,20);
cout<<ans->data<<endl;
return 0;
}