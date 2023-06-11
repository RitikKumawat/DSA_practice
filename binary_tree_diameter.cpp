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
pair<int,int> fastDiameter(node* root){
    if(root==NULL){
        pair<int,int> p =make_pair(0,0);
        return p;
    }
    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 =right.first;
    int op3 = left.second+right.second+1;

    pair<int,int> ans ;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;

    return ans;
}
int diameter(node* root){
    return fastDiameter(root).first;
}
int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

cout<<diameter(root);
return 0;
}