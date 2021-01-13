#include <bits/stdc++.h>
using namespace std;
typedef complex<long double> point;

#define x real()
#define y imag()

const long double pi = acos(-1), two_pi = 2*pi ,eps = 1e-10;

int sgn(long double a) {return (a>eps) - (a<-eps);}

istream& operator>>(istream &in, point &p){
    long double a, b; in >> a >> b, p=point(a,b);
    return in;
}
long double degree_to_rad(long double angle){return angle*pi/180;}
long double rad_to_degree(long double angle){return angle*180/pi;}

long double dot(const point &a, const point &b){return (conj(a)*b).x;}
long double cross(const point &a, const point &b){return (conj(a)*b).y;}
long double cross(const point &a, const point &b, const point &c){return cross((a-c),(b-c));}

namespace std{
    bool operator<(const point &a, const point &b){
        long double d;
        if (abs(d = a.x - b.x) > eps)
            return d<0;
        if (abs(d = a.y - b.y) > eps)
            return d<0;
        return false;
    }
}

long double squared_dist(const point &a, const point &b){return norm(a-b);}
long double euclid_dist(const point &a, const point &b){return abs(a-b);} 
long double angle_elev(const point &b, const point &a){return arg(b-a);}
point polar_cartes(const long double &r, const long double &theta){return polar(r, theta);}
point cartesian_polar(const point &a){return point(abs(a), arg(a));}

point rotate_origin(const point &a, const long double &t){
    return a * polar_cartes(1.0, t);
}
point rotate_pivot(const point &a, const point &p, const long double theta){
    return (a-p) * polar_cartes(1.0, theta) + p;
}


long double getAngle(const point &a, const point &b, const point &c){
    return abs(remainder(arg(a-b) - arg(c-b), two_pi));
}
long double triangleArea(const point &a, const point &b, const point &c){
    const long double A= abs(b-a), B=abs(c-b), C= abs(a-c), s=(A+B+C)/2;
    return sqrt(s*(s-A)*(s-B)*(s-C));
}

//line operation
long double slope(const point &a, const point &b) {return tan(arg(b-a));}
bool parallel(const point &a, const point &b, const point &p, const point &q){
    const auto c = b-a, u = p - a, v = q - b;
    return abs(cross(u,c) - cross(v,c)) < eps;
}
point intersection(const point &a, const point &b, const point &p , const point &q){
    auto c1 = cross(p-a, b-a), c2 = cross(q-a, b-a);
    return (c1 * q - c2 * p) / (c1 - c2);
}

//segment intersection
bool inter1(long double a, long double b, long double c, long double d){
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool check_inter(const point &a, const point &b, const point &c, const point &d){
    if(cross(a,d,c) == 0 && cross(b,d,c) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(cross(b, c,a)) != sgn(cross(b, d,a)) &&
           sgn(cross(d, a,c)) != sgn(cross(d, b,c));
}

//return the closest two points and their euclidean distance
long long closest(vector<point> vp){
    int n = vp.size();
    sort(vp.begin(), vp.end());
    set<point> s;
    long long best = 1e18;
    int j = 0;
    for(int i =0 ; i < n ; i++){
        int d = ceil(sqrt(best));
        while(vp[i].x - vp[j].x >= best){
            s.erase(point(vp[j].y, vp[j].x));
            j += 1;
        }
        auto a = s.lower_bound(point(vp[i].y - d, vp[i].x));
        auto b = s.upper_bound(point(vp[i].y + d, vp[i].x));

        for(auto it = a ; it != b ; it++){
            int dx = vp[i].x - it->y;
            int dy = vp[i].y - it->x;
            best = min(best, 1LL * dx * dx + 1LL * dy * dy);
        }
        s.insert(point(vp[i].y, vp[i].x));
    }
    return best;
    
}
//project p onto vector v
//v * dot(p,v) / norm(v);

//project p onto line (a,b)
//a + (b-a) * dot(p-a, b-a) / norm(b-a)


//reflect p across line (a,b)
//a + conj((p-a) / (b-a)) * (b-a)



/*
 * Usage
 *
 * point a = 2; --> (2,0)
 * point b(3,7) --> (3,7)
 * long double r = 3.0 --> scalar
 *
 */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> v(n);
    for(auto &i : v){
        long long temp1,temp2;
        cin >> temp1 >> temp2;
        i = point(temp1, temp2);
    }
    cout << closest(v);

}
