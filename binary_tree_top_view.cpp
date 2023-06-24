#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


vector<int> TopView(node* root){
    vector<int> ans;
    if(root==NULL)
        return ans;

    queue<pair<node*,int>> q;
    map<int,int> topnode;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* frontNOde = temp.first;
        int hd = temp.second;
        if(topnode.find(hd)==topnode.end())
            topnode[hd]=frontNOde->data;
        if(frontNOde->left)
            q.push(make_pair(frontNOde->left,hd-1));
        
        if(frontNOde->right)
            q.push(make_pair(frontNOde->right,hd+1));
        
    }
    for(auto i:topnode)
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

vector<int> a= TopView(root);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;
return 0;
}