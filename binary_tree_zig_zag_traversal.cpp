#include<iostream>
#include<queue>
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

vector<int> zig_zag_traversal(node* root){
    vector<int> result;
    if(root==NULL)
        return result;
    queue<node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            node* frontnode = q.front();
            q.pop();
            int index = leftToRight ? i: size-i-1;
            ans[index]=frontnode->data;

            if(frontnode->left)
                q.push(frontnode->left);
            if(frontnode->right)
                q.push(frontnode->right);
            
        }
        leftToRight = !leftToRight;
        for(auto i: ans)
            result.push_back(i);
    }
    return result;
}
int main(){

node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

vector<int> a = zig_zag_traversal(root);

for(auto i: a){
    cout<<i<<" ";
}cout<<endl;

return 0;
}