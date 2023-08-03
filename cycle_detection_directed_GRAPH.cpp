#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


bool checkCycle(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>>&adj){
    visited[node]=true;
    dfsVisited[node]=true;

    for(auto neighbor: adj[node]){
        if(!visited[neighbor]){
            bool cycleDetectd = checkCycle(neighbor,visited,dfsVisited,adj);
            if(cycleDetectd)
                return true;
            
        }
        else if (dfsVisited[neighbor]){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}

int Detect_cycle_Directed(int n, vector<pair<int,int>> edges)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycleDetect = checkCycle(i,visited,dfsVisited,adj);
            if(cycleDetect)
                return true;
        }
    }
    return false;
}

int main(){

return 0;
}