#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u,v,w;
    bool operator<(edge const &other){
        return w < other.w;
    }
};
int parent[100001], dist[100001];
edge adj[100001];
vector<edge> result;
int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(dist[a] < dist[b]) swap(a,b);
        parent[b] = a;
        if(dist[a] == dist[b]) dist[a]+=dist[b];
    }
}
int main(){
    int n, m, cost = 0;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i, dist[i] = 0;
    }
    for(int i = 0 ; i < m ; i++){
       cin >> adj[i].u >> adj[i].v >> adj[i].w;
    }

    sort(adj, adj + m);

    for(edge e : adj){
        if(find(e.u) != find(e.v)){
            cost += e.w;
            result.push_back(e);
            merge(e.u, e.v);
        }
    }

    cout << cost << "\n";
    for(auto &i : result){
        cout << i.u << " " << i.v << " " << i.w << "\n";
    }
}
