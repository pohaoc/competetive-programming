#include <bits/stdc++.h>
using namespace std;
struct pt{
    long long x,y;
};

bool cmp(pt a, pt b){return a.x < b.x || (a.x == b.x && a.y < b.y);}
bool cw(pt a, pt b, pt c){return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;}
bool ccw(pt a, pt b, pt c){return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;}

//takes care of collinear points: switch ccw/cw and take out if statement
void cconvex(vector<pt> &a){
    int n = a.size();
    sort(a.begin(), a.end(), &cmp);
    vector<pt> up, down;
    down.reserve(n+1);
    for(int i =0 ; i< n ; i++){
        while(up.size() > 1 && ccw(up[up.size()-2],up[up.size()-1],a[i])){
            up.pop_back();
        }
        up.emplace_back(a[i]);
        l1++;
        while(down.size() > 1 && cw(down[down.size()-2],down[down.size()-1],a[i])){
            down.pop_back();
        }
        down.emplace_back(a[i]);
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
//regular graham scan
void convexhull(vector<pt> &a){
    int n = a.size();
    if(n == 1) return;
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1 ; i < (int)n ; i++){
        if(i == n - 1 || cw(p1, a[i], p2)){
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i == n - 1 || ccw(p1, a[i], p2)){
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }

    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    vector<pt> v(t);
    for(auto &i : v){
        long long a,b;
        cin >> a >> b;
        i.x = a;
        i.y = b;
    }
    cconvex(v);
    cout << v.size() << '\n';
    for(auto &i : v){
        cout << i.x << " " << i.y << "\n";
    }


}
