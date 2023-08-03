#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void prepareAdjlist(unordered_map<int,list<int>> &adj,vector<pair<int,int>>edges )
{
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i: adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }

        }
    }
}
vector<int> BFS(int vertex,vector<pair<int,int>>edges){
    unordered_map<int,list<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjlist(adj,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}


int main(){

return 0;
}