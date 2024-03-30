#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DAG {
public:
    int V;
    vector<vector<int>> adj;

    void DFSVisit(int v, vector<bool>& visited, vector<int>& postOrder) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); ++i)
            if (!visited[adj[v][i]])
                DFSVisit(adj[v][i], visited, postOrder);
        postOrder.push_back(v);
    }

    DAG(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    vector<int> topologicalSort() {
        vector<bool> visited(V, false);
        vector<int> postOrder;
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                DFSVisit(i, visited, postOrder);
        return postOrder;
    }
};

void CutVertex(int V,int E,int s,int t,DAG g){
    vector<vector<int>> adj=g.adj;
    vector<int> topo=g.topologicalSort();
    vector<int> cutVertex={};
    vector<int> index(V);
    for(int i=0;i<topo.size();i++){
        index[topo[i]]=i;
    }
    int mx=-1;
    for(int i=index[s];i<index[t];i++){
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
}

int main() {
    int V,E;
    cout<<"Input V and E";
    cin>>V>>E;
    cout<<"Input s and t";
    DAG g(V);
    int s,t;
    cin>>s>>t;
    cout<<"Input the graph edges";
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    CutVertex(V,E,s,t,g);
    return 0;
}
