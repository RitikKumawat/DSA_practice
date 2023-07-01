#include<iostream>
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
void preorder(node* root){
    if(root==NULL)
        return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->left);
}
void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->left);
}
void postorder(node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->left);
    cout<<root->data;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

    }
}
int main(){
node* root=NULL;
take_input(root);
cout<<"Printing BST in Level ORder "<<endl;
levelOrderTraversal(root);
return 0;
}