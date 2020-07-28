
long long levdist(string a, string b){
    ll n = a.length();
    ll m = b.length();
    int dp[n+1][m+1];
    memset(dp, mod, sizeof dp);
    dp[0][0] = 0;

    for(int i = 0; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            if(i&&j) dp[i][j] = min(dp[i][j], (a[i-1]!=b[j-1])+dp[i-1][j-1]);
        }
    }
    return dp[n][m];
    
}
