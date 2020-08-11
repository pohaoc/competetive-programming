#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int n;
int t[2*mxN];

void build(){
    for (int i = n - 1 ; i > 0 ; i--){
        t[i] =min(t[i<<1], t[i<<1|1]);
    }
}

void modify(int p, int val){
    for(t[p+=n] = val; p > 1 ; p >>= 1)
        t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r){
    int res = INT_MAX;
    for(l += n , r += (n+1) ; l < r ; l >>=1, r>>=1){
        if(l&1)
        res = min(res, t[l++]);
        if(r&1)
        res = min(res, t[--r]);
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> t[n + i];
    }
    build();
    int s;
    cin >> s;
    for(int i = 0; i < s ; i++){
        int a,b;
        cin >> a >> b;
        cout << query(a,b) << "\n";
    }
}



