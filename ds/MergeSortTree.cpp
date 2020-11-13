#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int mod = 1e9+7;
const ll INF = 1e18;
vector<int> t[4*30001];

void build(int arr[], int v, int tl, int tr){
    if(tl == tr){
        t[v] = vector<int>(1, arr[tl]);
    }else{
        int mid = (tl + tr)/ 2 ;
        build(arr, v*2, tl , mid);
        build(arr, v*2+1 , mid+ 1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), back_inserter(t[v]));
    }
}
int query(int v, int tl, int tr, int l, int r, int k){
    if(l > r) return 0;
    if (l == tl && r == tr){
        return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
    }
    int mid = (tl+tr) >> 1;
    return query(2 * v, tl, mid, l, min(r, mid), k ) + query(2 * v + 1 , mid+1, tr, max(l, mid+1), r, k );
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int arr[30001];
    for(int i =1 ; i <= n ; i++){
        cin >> arr[i];
    }
    build(arr, 1,1,n);
    int q;
    cin>> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;

        cout << query(1, 1, n, a, b ,c) << "\n";
    }

}
