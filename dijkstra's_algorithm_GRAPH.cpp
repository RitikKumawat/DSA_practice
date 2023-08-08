#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<list>
using namespace std;


// We have to find the shortest distance between all the nodes from sorce node
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    set<pair<int,int>> st;
    vector<int> dist(vertices);

    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());
        int topNode = top.second;
        int nodeDistance = top.first;

        st.erase(st.begin());

        for(auto neighbor: adj[topNode]){
            if(neighbor.second + nodeDistance < dist[neighbor.first] ){
                auto record = st.find(make_pair(dist[neighbor.first],neighbor.first));
                if(record != st.end()){
                    st.erase(record);
    
                }
                dist[neighbor.first] = nodeDistance + neighbor.second;
                st.insert(make_pair(dist[neighbor.first],neighbor.first));
            }
        }
    }
    return dist;
}


int main(){

return 0;
}