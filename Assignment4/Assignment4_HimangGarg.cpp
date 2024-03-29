#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int V=12;
    vector<vector<int>> edges={{0,1},{1,3},{3,2},{2,4},{4,5},{5,6},{6,8},{8,7},{7,9},{9,10},{10,11},{0,3},{3,4},{3,6},{6,7},{2,5},{8,9},{6,9},{9,11},{2,6},{3,5},{4,6}};
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> topo={0,1,3,2,4,5,6,8,7,9,10,11};
    vector<int> cutVertex={};
    vector<int> index(V);
    for(int i=0;i<topo.size();i++){
        index[topo[i]]=i;
    }
    int mx=-1;
    for(int i=0;i<topo.size()-1;i++){
        int v=topo[i];
        if(v==topo[mx]){
            cutVertex.push_back(v);
        }
        for(int j=0;j<adj[v].size();j++){
            if(index[adj[v][j]]>mx){
                mx=index[adj[v][j]];
            }
        }
    }
    for(int i=0;i<cutVertex.size();i++){
        cout<<cutVertex[i]<<' ';
    }
    return 0;
}
