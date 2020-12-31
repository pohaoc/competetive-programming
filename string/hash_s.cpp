long long getHash(string const& s){
    const int p = 31; //use 53 if input has lower and uppercase
    const int mod = 1e9+9;
    long long hash = 0;
    long long p_pow = 1;
    for(char c : s){
        hash = (hash + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash;
}

