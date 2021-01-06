int minrotate(string s){
    int a=0, n= s.size(); s+= s;
    for(int b = 0 ; b < n ; b++){
        for(int i = 0; i < n ; i++){
            if(a+i == b || s[a+i] < s[b+i]){
                b+= max(0, i-1);
                break;
            }
            if(s[a+i] > s[b+i]){
                a = b;
                break;
            }
        }
    }
    return a;
}


