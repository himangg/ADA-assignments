#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

int gif(float n){
    return (n/1);
}

int lif(float n){
    if(n-gif(n)==0.0){
        return (n);
    }
    return ((n/1)+1);
}

int countNegative(vector<ll> v){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            count++;
        }
    }
    return count;
}

bool containZero(vector<ll> v){
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            return true;
        }
    }
    return false;
}

vector<ll> findDivisors(ll n) {
    vector<ll> divisors1={};
    vector<ll> divisors2={};
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors1.push_back(i);
            if (i != n / i) {
                divisors2.push_back(n / i);
            }
        }
    }
    for(ll i=divisors2.size()-1;i>=0;i--){
        divisors1.push_back(divisors2[i]);
    }
    return divisors1;
}

void displayVector(vector<ll> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll binarySearch(vector<ll> v, ll target,ll start, ll end){
    if(end-start==0){
        return start;
    }
    ll index = (start+end)/2;
    if(v[index]==target){
        return index;
    }
    else if(v[index]<target){
        return binarySearch(v,target,index+1,end);
    }
    else{
        return binarySearch(v,target,start,index-1);
    }
}

bool compareAbsolute(int a, int b) {
    return abs(a)<=abs(b);
}

class vertex {
public:
    vector<int> dimension;
    bool visited = false;
    bool pathVisited = false;
    vector<int> adj;
    vertex(vector<int> dimension) {
        this->dimension = dimension;
    }
    void addEdge(int v) {
        this->adj.push_back(v);
    }
};

int bfs(vector<vertex*>& vertexes, vector<int>& parent, int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int min_capacity = q.front().second;
        q.pop();

        for (int v_index : vertexes[u]->adj) {
            if (parent[v_index] == -1) {
                parent[v_index] = u;
                int new_flow = min(min_capacity, 1);
                if (v_index == t)
                    return new_flow;
                q.push({v_index, new_flow});
            }
        }
    }
    return 0;
}

int fordFulkerson(vector<vertex*>& vertexes, int s, int t) {
    int maxFlow = 0;
    vector<int> parent(vertexes.size());
    int new_flow;

    while (new_flow = bfs(vertexes, parent, s, t)) {
        maxFlow += new_flow;

        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            vertexes[prev]->adj.erase(remove(vertexes[prev]->adj.begin(), vertexes[prev]->adj.end(), cur), vertexes[prev]->adj.end());
            vertexes[cur]->adj.push_back(prev);
            cur = prev;
        }
    }
    return maxFlow;
}

void solve() {
    ll n;
    cin >> n;
    vector<vertex*> vertexes = {};

    vertex* s = new vertex({0, 0, 0});
    vertexes.push_back(s);
    vertex* t = new vertex({0, 0, 0});
    vertexes.push_back(t);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex* v = new vertex({a, b, c});
        vertexes.push_back(v);
        s->addEdge(i + 2);
    }

    for (int i = 0; i < n; i++) {
        vertex* v = new vertex({vertexes[i + 2]->dimension[0], vertexes[i + 2]->dimension[1], vertexes[i + 2]->dimension[2]});
        vertexes.push_back(v);
        v->addEdge(1);
    }

    for (int i = 2; i < n + 2; i++) {
        for (int j = n + 2; j < 2 * (n + 1); j++) {
            if (vertexes[j]->dimension[0] > vertexes[i]->dimension[0] && vertexes[j]->dimension[1] > vertexes[i]->dimension[1] && vertexes[j]->dimension[2] > vertexes[i]->dimension[2]) {
                vertexes[i]->addEdge(j);
            }
        }
    }

    int maxFlow = fordFulkerson(vertexes, 0, 1);
    cout << "Maximum Flow: " << maxFlow << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
