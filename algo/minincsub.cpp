
// For calculating the min # of increasing subseq 
// longest decreasing subsequence
template<typename T>
T minincsub(vector<T> &v){
    multiset<T> ms;
    for(int i = 0 ; i < v.size() ; i++){
        auto itr = ms.lower_bound(v[i]);
        if(itr == ms.begin())
            ms.insert(v[i]);
        else{
            itr--;

            ms.erase(itr);
            ms.insert(v[i]);
        }
    }
    return ms.size();
}
//For calculating the min # of decreasing subseq
// longest non-decreasing subsequence or longest increasing subseq if change to lower_bound?
template<typename T>
T minnondecsub(vector<T> &v){
    multiset<T> ms;
    for(int i = 0 ; i < v.size() ; i++){
        auto itr = ms.upper_bound(v[i]);
        if(itr == ms.end()){
            ms.insert(v[i]);
        }else{
            ms.erase(itr);
            ms.insert(v[i]);
        }
    }

    return ms.size();
}
