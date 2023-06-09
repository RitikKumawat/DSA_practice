#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
node* buildTree(node* root){
    cout<<"Enter data :"<<endl;
    int d;
    cin>>d;
    root= new node(d);
    if(d==-1){
        return NULL;
    }
    cout<<"Enter data for inserting at left of "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting at right of "<<d<<endl;
    root->right = buildTree(root->right);
    return root;
}
void preorder(node* root){
    
    if(root==NULL)
        return;
    cout<< root->data;

    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    
    if(root==NULL)
        return;

    inorder(root->left);
    cout<< root->data;
    inorder(root->right);
}
void postorder(node* root){
    
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data;
}


int main(){
node* root=new node(1);
root->left =new node(2);
root->right =new node(3);
root->left->left =new node(4);
root->left->right =new node(5);
root->right->left =new node(6);
root->right->right =new node(7);

preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;



return 0;
}