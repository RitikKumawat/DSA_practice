#include<iostream>
#include<map>
#include<vector>
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

vector<int> BottomView(node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    queue<pair<node*,int>> q;
    map<int,int> topnode;

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node* frontnode= temp.first;
        int hd=temp.second;

        topnode[hd]=frontnode->data;
        if(frontnode->left)
            q.push(make_pair(frontnode->left,hd-1));
        if(frontnode->right)
            q.push(make_pair(frontnode->right,hd+1));
    }
    for(auto i: topnode)
        ans.push_back(i.second);

    return ans;
}


int main(){
node* root = new node(1);
root->left = new node(2);
root->left->left = new node(4);
root->right = new node(3);
root->right->left = new node(5);
root->right->left->left = new node(6);

vector<int> a = BottomView(root);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;
return 0;
}