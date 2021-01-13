#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int mod = 1e9+7;
const ll INF = 1e18;

vector<pair<long long,long long>> adj[100001];
ll p[100001];

//1 as source node
vector<ll> dijkstra(int n){
    priority_queue<pair<long long,long long> , vector<pair<long long,long long>>, greater<pair<long long,long long>> > pq;
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        long long curr = pq.top().second;
        long long d = pq.top().first;

        pq.pop();
        if(d != dist[curr]) continue;

        for(auto edge : adj[curr]){
            long long v = edge.first;
            long long w = edge.second;
            if(dist[curr] + w < dist[v]){
                dist[v] = dist[curr] + w;
                p[v] = curr;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;

}

vector<ll> restore(int n){
    vector<long long> path;
    for(long long v = n ; v != 1 ; v= p[v]){
        path.push_back(v);
    }
    path.push_back(1);

    reverse(path.begin(),path.end());
    return path;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,tw;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b >> tw;
        adj[a].push_back({b,tw});
        adj[b].push_back({a,tw});
    }
    auto v = dijkstra(n);
    auto path = restore(n);
    if(v[n] = INF) cout << "-1";
    else{
        for(auto &i : path){
            cout << i << " ";
        }
    }

}


