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
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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

node* minvalue(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* maxvalue(node* root){
    node* temp=root;
    while(temp->right!=NULL)
        temp=temp->right;

    return temp;
}

node* deleteNode_BST(node* root, int val){
    if(root==NULL)
        return root;
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;    
        }
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minvalue(root->right)->data;
            root->data=mini;
            root->right=deleteNode_BST(root->right,mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left = deleteNode_BST(root->left,val);
        return root;
    }
    else{
        root->right = deleteNode_BST(root->right,val);
        return root;
    }
}


int main(){
node* root=NULL;
take_input(root);
cout<<"Printing BST in Level ORder "<<endl;
levelOrderTraversal(root);
cout<<endl;
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;

cout<<"Max value in BST is: "<<maxvalue(root)->data<<endl;
cout<<"Min value in BST is: "<<minvalue(root)->data<<endl;

deleteNode_BST(root,10);

inorder(root);
return 0;
}