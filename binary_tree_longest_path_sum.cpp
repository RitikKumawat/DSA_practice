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
void solve(node*root, int sum,int &maxsum,int len, int &maxlen){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum = max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}
int longestPath(node* root){
    int sum=0;
    int maxsum= INT_MIN;
    int len=0;
    int maxlen=0;

    solve(root,sum,maxsum,len,maxlen);
    return maxsum;

}

int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

cout<<longestPath(root)<<endl;
return 0;
}