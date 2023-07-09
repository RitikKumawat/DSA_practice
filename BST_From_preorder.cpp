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

node* insertIntoBST(node* &root, int d){
    if(root ==NULL)
    {
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

void take_input(node* &root){
    int data;
    cout<<"Enter data to insert in BST"<<endl;
    cout<<"Enter -1 when you are done with giving output"<<endl;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
node* solve(vector<int> preorder,int mini, int maxi, int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi)
        return NULL;
    
    node* root = new node(preorder[i]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}
node* preordertoBST(vector<int> preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);

}

int main(){

return 0;
}