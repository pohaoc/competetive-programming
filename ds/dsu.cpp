int parent[10001], rank[10001];
//path compression
int find(int a){
    if(a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}
//union by rank
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(rank[a] < rank[b])
            swap(a,b);
        parent[b] = a;
        rank[a] += rank[b];
    }
}
