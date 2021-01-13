struct job{
    int id,s,f,w;
    bool operator<(job &other){
        return f < other.f;
    }
};
//regular nlogn wis
int wis(int n, vector<job> intervals){
    sort(intervals.begin(), intervals.end());
    vector<int> start(n), finish(n), p;
    p.reserve(n);
    for(int i = 0 ; i < n ;i++){
        start[i] = intervals[i].s;
        finish[i] = intervals[i].f;
    }
    for(int i = 0; i < n ; i++){
        int j = (upper_bound(finish.begin(), finish.end(), start[i]) - finish.begin()) - 1;
        p.emplace_back(j);
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i =1 ; i <= n ; i++){
        dp[i] = max(intervals[i-1].w + dp[p[i-1]+1],dp[i-1]);
    }
    return dp[n];
}
//with k constraint
vector<job> wisk(int n, int k, vector<job> intervals){
    sort(intervals.begin(), intervals.end());
    vector<int> start(n), finish(n), p;
    p.reserve(n);
    for(int i = 0 ; i < n ;i++){
        start[i] = intervals[i].s;
        finish[i] = intervals[i].f;
    }
    for(int i = 0; i < n ; i++){
        int j = (upper_bound(finish.begin(), finish.end(), start[i]) - finish.begin()) - 1;
        p.emplace_back(j);
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    vector<vector<bool>> B(n+1, vector<bool>(k+1));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            auto a = intervals[i-1].w + dp[p[i-1]+1][j-1];
            auto b = dp[i-1][j];
            dp[i][j] = max(a, b);
            B[i][j] = a > b ? 1 : 0;
        }
    }
    
    vector<job> schedule;
    schedule.reserve(n);
    while(n > 0 && k > 0){
        if(B[n][k] == 1){
            schedule.emplace_back(intervals[n-1]);
            n = p[n-1] + 1;
            k = k - 1;
        }else{
            n = n -1;
        }
    }
    
    return schedule;

}

/*
 * Usage
 * cin >> n >> k
 * vector<job> j(n);
 * trav(i,j):
 * cin >> j.id >> j.s >> j.f >> j.w; 
 *
 * OPTION 1:
 * wis -> returns the optimal value
 * OPTION 2:
 * wisk(n,k,j) -> returns schedule
 *
 */
