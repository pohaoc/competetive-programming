typedef complex<long double> point;
#define x real()
#define y imag()

long double dot(point a, point b){
    return (conj(a) * b).x;
}
//ax*by-ay*bx
long double cross(point a, point b){
    return (conj(a) * b).y;
}

//squared distance
long double squared_dist(point a, point b){
    return norm(a-b);
}

//euclidean distance
long double euclid_dist(point a, point b){
    return abs(a-b);
}

//angle of elevation
long double angle_elev(point a, point b){
    return arg(b-a); 
}

//slope of line
long double slope(point a, point b){
    return tan(arg(b-a));
}

//polar to cartesian
long double polar_cartes(long double r){
    return polar(r, theta);
}

//rotation about origin
long double rotate_origin(point a){
    return a * polar(1.0, theta)
}

//rotate about pivot p
long double rotate_pivot(point a, point p){
    return (a-p) * polar(1.0, theta) + p;
}

//angle ABC
long double getAngle(point a, point b, point c){
    return abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
}


//project p onto vector v
//v * dot(p,v) / norm(v);


//project p onto line (a,b)
//a + (b-a) * dot(p-a, b-a) / norm(b-a)


//reflect p across line (a,b)
//a + conj((p-a) / (b-a)) * (b-a)


//intersection of line (a,b) and (p,q)
point intersection(point a, point b, point p, point q){
    long double c1 = cross(p-a,b-a), c2 = cross(q-a, b-a);
    return (c1 * q - c2 * p) / (c1 -c2);
}

/*
 * Usage
 *
 * point a = 2; --> (2,0)
 * point b(3,7) --> (3,7)
 * long double r = 3.0 --> scalar
 *
 */



