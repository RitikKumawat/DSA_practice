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
void solve(node* root, vector<int> &ans,int level){
    if(root==NULL)
        return ;
    
    if(level==ans.size())
        ans.push_back(root->data);
    
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);

    
}

vector<int> leftView(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}
int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

vector<int> a = leftView(root);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;

return 0;
}