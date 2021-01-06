//for odd length
vector<int> oddpalindrome(const string& s){
    int n = s.length();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}

//for even length, alternatively we can pad # to make it odd
vector<int> evenpalindrome(const string& s){
    int n = s.length();
    vector<int> d2(n);
    for(int i =0, l = 0, r = -1; i < n ; i++){
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i + 1);
        while( 0 <= i - k - 1 && i + k < n && s[i-k-1] == s[i+k]){
            k++;
        }
        d2[i] = k--;
        if(i+k > r){
            l = i -k -1;
            r = i - k;
        }
    }
    return d2;
}

//this function returns the longest palindrome substring in s in O(n)
string longestpalindrome(const string& s){
    string modify = "#";
    for(int i =0 ; i < s.size() ; i++){
        modify = modify + s[i] + "#";
    }
    int n = modify.length();
    int most = 0;
    int most_pos;
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && modify[i - k] == modify[i + k]) {
            k++;
        }
        if(k> most){
            most = k;
            most_pos = i;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    string ans = "";
    for(int i = most_pos - most + 1 ; i < most_pos + most - 1; i++){
        if(modify[i] != '#')
            ans += modify[i];
    }
    return ans;
}

