
#include <bits/stdc++.h>
#define ll long long
#include <limits>
using namespace std;

class vertex{
public:
    vector<int> dimension;
    bool visited= false;
    bool pathVisited= false;
    vector<vertex*> adj={};
    vertex(vector<int> dimension){
        this->dimension=dimension;
    }
    void addEdge(vertex* v){
        this->adj.push_back(v);
    }
};

void fordFulkerson(vector<vertex*>& vertexes){
    if(vertexes[0]->adj[0]->adj[0]->adj[0]==vertexes[vertexes.size()-1]){
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<vertex*> vertexes={};

    vertex* s=new vertex({0,0,0});
    vertexes.push_back(s);
    vertex* t=new vertex({100000,100000,100000});
    vertexes.push_back(t);

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vertex* v=new vertex({a,b,c});
        vertexes.push_back(v);
        s->addEdge(v);
    }

    for(int i=0;i<n;i++){
        vertex* v=new vertex({vertexes[i+2]->dimension[0],vertexes[i+2]->dimension[1],vertexes[i+2]->dimension[2]});
        vertexes.push_back(v);
        v->addEdge(t);
    }

    for(int i=2;i<n+2;i++){
        for(int j=n+2;j<2*(n+1);j++){
            if(vertexes[j]->dimension[0]>vertexes[i]->dimension[0] && vertexes[j]->dimension[1]>vertexes[i]->dimension[1] && vertexes[j]->dimension[2]>vertexes[i]->dimension[2]){
                vertexes[i]->addEdge(vertexes[j]);
            }
        }
    }
}

int main() {
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
