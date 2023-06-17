#include<iostream>
#include<algorithm>
#include<unordered_map>
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
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;

}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+height(root->right)+1;
    int ans = max(op1,max(op2,op3));

    return ans;
}
pair<int,int> fast_diameter(node* root){
    if(root==NULL){
        pair<int,int> p =make_pair(0,0);
        return p;
    }
    pair<int,int> left = fast_diameter(root->left);
    pair<int,int> right = fast_diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int> ans ;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){

node* root = new node(1);
root->left = new node(2);
root->right = new node(7);
root->left->left = new node(3);
root->left->right = new node(4);

cout<<height(root)<<endl;
cout<<diameter(root)<<endl;
cout<<fast_diameter(root).first<<endl;

preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;

return 0;
}