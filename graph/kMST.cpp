#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int parent[10001], dist[10001];

int find(int a){
    if(a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(dist[a] < dist[b])
            swap(a,b);
        parent[b] = a;
        dist[a] += dist[b];
        return true;
    }
    return false;
}

struct edge{
int u,v,w;
    bool operator<(edge const &other){
        return w < other.w;
    }
};
vector<edge> edges;

struct Fracture{
    bitset<1225> b;
    vector<int> sp;
    int w =0, f=0;
    Fracture(bitset<1225> _b, int _f): b(_b), f(_f){
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i;
            dist[i] = 0;
        }

        for(int i = 0 ; i < m ; i++){
            if(!b[i] && merge(edges[i].u,edges[i].v))
                sp.push_back(i), w += edges[i].w;
        }
    }
};
bool operator<(const Fracture& l, const Fracture& r){return l.w > r.w;}

int main(){
    cin >> n >> m >> k;
    for(int i =0 ; i < m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(), edges.end());
    priority_queue<Fracture> pq;
    pq.push({bitset<1225>(), 0});
    for(int i = 1 ; i<= k ; i++){
        if(!pq.size()){
            cout << "-1" << '\n';
            break;
        }
        auto curr = pq.top(); pq.pop();
        if(i == k){
            cout << k << "th smallest ";
            cout << curr.w << '\n';
        }
        while(curr.f < curr.sp.size()){
            bitset<1225> temp = curr.b;
            temp[curr.sp[curr.f]] = 1;
            auto fract = Fracture(temp, curr.f);
            if(fract.sp.size() == n-1) pq.push(fract);
            curr.f++;
        }
    }
}
