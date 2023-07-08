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
bool TwoSum(node* root, int target){
    vector<int> inorderVal;
    inorder(root,inorderVal);
    int i=0,j=inorderVal.size()-1;
    while(i<j){
        int sum = inorderVal[i]+inorderVal[j];
        if(sum==target)
            return true;
        else if(sum>target)
            j--;
        else    
            i++;
    }
    return false;
}

int main(){
node* root=NULL;
take_input(root);

if(TwoSum(root,18)){
    cout<<"The Target is present"<<endl;

}
else{
    cout<<"The Target is not present"<<endl;
}
return 0;
}