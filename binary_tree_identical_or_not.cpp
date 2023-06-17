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

bool isIdentical(node* r1, node* r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL && r2!=NULL)
        return false;
    if(r1!=NULL && r2==NULL)
        return false;
    
    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    bool curr = r1->data==r2->data;

    if(curr && left && right)
        return true;
    else
        return false;
}

int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

node* root2 = new node(1);
root2->left = new node(2);
root2->left->left = new node(4);
root2->right = new node(3);
root2->right->left = new node(5);
root2->right->left->left = new node(6);

cout<<isIdentical(root,root2);

return 0;
}