const int mod = 1e9+7;
const ll M2 = (ll)mod*mod;
#define mat vector<vector<ll>>

mat mult(mat &a, mat &b){
    mat res(a.size(), vector<ll>(b[0].size()));
    for(unsigned int i = 0 ; i < a.size() ; i++){
        for(unsigned int j = 0 ; j < b.size() ; j++){
            for(unsigned int k = 0 ; k < b[0].size() ; k++){
                res[i][k] += a[i][j] * b[j][k];
                if(res[i][k] >= M2)
                    res[i][k] -= M2;
            }
        }
    }
    return res;
}
mat mpow(ll b){
    mat res = {{0,1}};
    mat M = {{0,1},{1,1}};
    while(b){
        if(b&1)
            res = mult(res,M);
        M = mult(M,M);
        b>>=1;
    }
    return res;
}
