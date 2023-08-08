#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

void toposort(int node, unordered_map<int,bool> &visited, stack<int> &s, unordered_map<int,list<int>> &adj){
    visited[node]=1;
    
    for(auto neighbor: adj[node]){
        if(!visited[neighbor]){
            toposort(node,visited,s,adj);
        }
    }
    s.push(node);
}

vector<int> topological_sort(vector<vector<int>> edges, int v, int e){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());

        s.pop();
    }
    return ans;
}
int main(){

return 0;
}