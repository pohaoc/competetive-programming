#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int n;
pair<int,int> t[2*mxN];

pair<int,int> combine(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) return a;
    if(a. first > b.first) return b;
    return make_pair(a.first, a.second+b.second);
}

void build(){
    for (int i = n - 1 ; i > 0 ; i--){
        t[i] =combine(t[i<<1], t[i<<1|1]);
    }
}

void modify(int p, int val){
    for(t[p+=n] = {val, 1}; p > 1 ; p >>= 1)
        t[p>>1] = combine(t[p], t[p^1]);
}

pair<int,int> query(int l, int r){
    pair<int,int> ra = {INT_MAX, 1};
    pair<int,int> rb = {INT_MAX, 1};
    for(l += n , r += n ; l < r ; l >>=1, r>>=1){
        if(l&1)
        ra = combine(ra, t[l++]);
        if(r&1)
        rb = combine(rb, t[--r]);
    }
    return combine(ra,rb);
}

int main(){
    //how many elements
    cin >> n;
    int s; //how many query
    cin >> s;
    for(int i = 0 ; i < n ; i++){
        cin >> t[n + i].first;
        t[n+i].second = 1;
    }
    build();
    for(int i = 0; i < s ; i++){
        int a, b, c;
        cin >> a >> b >> c; // a = operation, b = left, c = right
        if(a== 1){
            modify(b,c);
        }
        if( a== 2){
            auto temp = query(b,c);
            cout << temp.first << " " << temp.second << "\n";
        }

    }
}




