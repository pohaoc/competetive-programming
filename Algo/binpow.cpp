uint64_t binpow(uint64_t a, uint64_t b, uint64_t m){
    a %= m;
    uint64_t res = 1;
    while(b > 0){
        if(b & 1)
            res=res*a;
        a = a * a;
        b>>=1;
    }
    return res;
}
