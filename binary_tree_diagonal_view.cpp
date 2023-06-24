#include<iostream>
#include<vector>
#include<queue>
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
vector<int> diagonalView(node* root){
    queue<node*> q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        while(temp){

        if(temp->left)
            q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }       
        
    }
    return ans;
}

int main(){

node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);


vector<int> a= diagonalView(root);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;

return 0;
}