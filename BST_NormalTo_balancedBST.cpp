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
void inorder(node*root , vector<int> &inorderVal){
    if(root==NULL)
        return;
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}
node* inorder_to_BST(int s, int e, vector<int> inorderVal){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    node* root = new node(inorderVal[mid]);
    root->left=  inorder_to_BST(0,mid-1,inorderVal);
    root->right=  inorder_to_BST(mid+1,e,inorderVal);
    return root;
}
node* BalancedBST(node* root){
    vector<int> inorderVal ;
    inorder(root,inorderVal);

    return inorder_to_BST(0,inorderVal.size()-1,inorderVal);
}
int main(){

return 0;
}