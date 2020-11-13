/* * * The following code uses Mo's Algorithm w/ hilbertorder optimization
 * The example calculates the number of distinct element in subsequence ai..aj
 *
 */

#include <bits/stdc++.h>

using namespace std;

constexpr int logn = 20;
constexpr int maxn = 1 << logn;

long long hilbertorder(int x, int y)
{
	long long d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | (rx * 3 ^ static_cast<int>(ry));
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}

struct Query{
    int l, r, idx;
    int64_t ord;
    inline void calcOrder(){
        ord = hilbertorder(l,r);
    }
};

inline bool operator<(const Query &a, const Query &b){
    return a.ord < b.ord;
}

Query Q[200001];
int arr[30001], ans[200001];
int freq[1000001];
int cnt;

void add(int pos){
    freq[arr[pos]]++;
    if(freq[arr[pos]] == 1)
        cnt++;
}
void rem(int pos){
    freq[arr[pos]]--;
    if(freq[arr[pos]] == 0)
        cnt--;
}

int main(){
    int n, q;
    cin >> n;
    for(int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }
    cin >> q;
    for(int i= 0 ; i < q ; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].idx = i;
        Q[i].calcOrder();
    }
    sort(Q, Q+q);
    //Mo's
    int ML = 0 , MR = -1;
    for(int i = 0 ; i< q; i++){
        int L = Q[i].l;
        int R = Q[i].r;

        while(ML > L)
            ML--, add(ML);
        while(MR < R)
            MR++, add(MR);

        while(ML < L)
            rem(ML), ML++;
        while(MR > R)
            rem(MR), MR--;
        ans[Q[i].idx] = cnt;
    }

    for(int i = 0; i < q ; i++){
        cout << ans[i] << "\n";
    }
}
