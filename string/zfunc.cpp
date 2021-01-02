#include <bits/stdc++.h>
using namespace std;

vector<int> z_func(string const& s){
    int n = (int) s.length();
    vector<int> z(n);
    for(int i = 1 , l = 0, r = 0; i < n ; ++i){
        if(i <= r)
            z[i] = min(r-i + 1, z[i-l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if( i + z[i] - 1 > r)
            l = i, r= i + z[i] - 1;

    }
    return z;
}
//using Z-function to search of pattern occurences
vector<int> substr_search(string const& s, string const& p){
    string combine = p + "$" + s;
    int P = p.size();
    int S = s.size();
    auto z = z_func(combine);
    vector<int> occur;
    for(int i =0 ; i< S ; i++){
        if(z[i + P + 1] == P)
            occur.push_back(i);
    }
    return occur;
}

//comptues the length of the longest common prefix of all string in the vector
int LCP(vector<string> s){
    //if(s.size() ==0) return "";
    string combine;
    vector<int> len;
    for(auto &i :s){
        combine += i;
        combine += "$";
        len.push_back(i.size());
    }
    auto v = z_func(combine);
    int start = combine.size() - 1;
    int res = INT_MAX;
    for(auto i = len.rbegin() ; i != len.rend() - 1; i++){
        start -= *i;
        res = min(res, v[start]);
        start -= 1;
    }

    /* if we want to return the lcp string

    res = res == INT_MAX ? s[0].size() : res; //if the string is a letter
    string ans;
    for(int i = 0 ; i < res ; i++){
        ans +=  s[0][i];
    }
    ans.erase(find(ans.begin(), ans.end() ,'\0'), ans.end());

    */
    return res;

}
int main(){
    vector<string> strs ={"flower", "dog", "flight"};
    auto res = LCP(strs);
    cout << res;
}

