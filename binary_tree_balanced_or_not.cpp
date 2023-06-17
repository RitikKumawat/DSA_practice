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

pair<bool,int> isBalanced_optimizedAPproach(node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = isBalanced_optimizedAPproach(root->left);
    pair<bool,int> right = isBalanced_optimizedAPproach(root->right);

    bool leftans = left.first;
    bool rightans = right.first;
    
    bool diff = abs(left.second - right.second)<=1;
    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;

    if(leftans && rightans && diff){
        ans.first=true;
    }
    else
        ans.first=true;

    return ans;

}

int main(){

node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

cout<<isBalanced_optimizedAPproach(root).first<<endl;

return 0;
}