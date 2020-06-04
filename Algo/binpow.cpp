long long binpow(long long a, long long b, int m){
    a %= m;
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res=res*a;
        a = a * a;
        b>>=1;
    }
    return res;
}
