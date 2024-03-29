#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
    int V;

public:
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void DFSVisit(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); ++i) {
            int adjacent = adj[v][i];
            if (!visited[adjacent])
                DFSVisit(adjacent, visited, Stack);
        }
        Stack.push(v);
    }

    vector<int> topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> Stack;
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                DFSVisit(i, visited, Stack);
        vector<int> topologicalOrder;
        while (!Stack.empty()) {
            topologicalOrder.push_back(Stack.top());
            Stack.pop();
        }
        return topologicalOrder;
    }
};

int main() {
    int V,E;
    cout<<"Input V and E";
    cin>>V>>E;
    cout<<"Input s and t";
    Graph g(V);
    int s,t;
    cin>>s>>t;
    cout<<"Input the graph edges";
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }

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
    return 0;


}
