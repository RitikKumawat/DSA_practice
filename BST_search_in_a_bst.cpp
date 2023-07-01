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

bool searchinBST_recursive(node* root, int x){
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    if(root->data>x)
        return searchinBST_recursive(root->left,x);
    else
        return searchinBST_recursive(root->left,x);
    


}
bool searchinBST_iterative(node* root,int x){
    node* temp=root;
    while(temp!=NULL){
        if(temp==NULL)
            return false;
        if(temp->data==x)
            return true;
        if(temp->data>x)
            temp=temp->left;
        else    
            temp=temp->right;
    }
    return false;
}

int main(){
node* root=NULL;
take_input(root);
if(searchinBST_iterative(root,4) && searchinBST_recursive(root,4) ){
    cout<<"Element present"<<endl;
}
else{
    cout<<"element does not present in BST"<<endl;
}
return 0;
}