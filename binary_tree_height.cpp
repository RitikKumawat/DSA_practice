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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left =height(root->left);
    int right =height(root->right);

    int ans = max(left,right)+1;
    return ans;
}

int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

cout<<height(root)<<endl;
return 0;
}