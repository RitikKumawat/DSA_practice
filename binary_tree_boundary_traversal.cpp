#include<iostream>
#include<vector>
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

void traverse_left(node* root, vector<int> & ans){
    if((root==NULL) || (root->left==NULL && root->right==NULL))
        return;
    ans.push_back(root->data);
    if(root->left)
        traverse_left(root->left,ans);
    else
        traverse_left(root->right,ans);
}
void traverse_leaf(node* root, vector<int> & ans){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverse_leaf(root->left,ans);
    traverse_leaf(root->right,ans);
    
}
void traverse_right(node* root, vector<int> & ans){
    if((root==NULL) || (root->left==NULL && root->right==NULL))
        return;
    if(root->right)
        traverse_right(root->right,ans);
    else    
        traverse_right(root->left,ans);
    ans.push_back(root->data);
}

vector<int> boundary(node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    ans.push_back(root->data);

    traverse_left(root->left,ans);

    traverse_leaf(root->left,ans);
    traverse_leaf(root->right,ans);

    traverse_right(root->right,ans);

    return ans;
}
int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

vector<int> a = boundary(root);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;

return 0;
}