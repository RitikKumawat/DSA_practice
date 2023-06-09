#include<iostream>
#include<queue>
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

void level_order_traversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp =q.front();
        
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
            
        }
    }
}

int main(){
node* root=new node(1);
root->left=new node(2);
root->left->left=new node(4);
root->left->right=new node(5);
root->right=new node(3);
root->right->left=new node(6);
root->right->right=new node(7);
// root=buildTree(root);

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
level_order_traversal(root);


return 0;
}