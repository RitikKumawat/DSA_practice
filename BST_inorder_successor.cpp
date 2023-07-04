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

node* inorder_Successor(node* root, int x){
    node* successor = NULL;
    
    while(root!=NULL){
        if(x>=root->data){
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
node* inorder_predecessor(node* root,int x){
    node* predecessor = NULL;
    while(root!=NULL){
        if(x<=root->data){
            root=root->left;
        }
        else{
            predecessor=root;
            root=root->right;
        }
    }
    return predecessor;
}
int main(){
node* root=NULL;
take_input(root);
// node* x = new node(8);
cout<<"Inorder Successor:"<<(inorder_Successor(root,5))->data<<endl;
cout<<"Inorder Predecessor:"<<(inorder_predecessor(root,5))->data;
return 0;
}