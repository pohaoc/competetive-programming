
//the minimum moves to remove all the palindrome in the string
int remove_palindrome(string s){
    int cnt = 0;
    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] == s[i-1]){ //len 2 palindrome
            s[i] = '#'; 
            cnt++;
        }else if(i > 1 && s[i] == s[i-2]){ //len 3 palindrome
            s[i] = '#';
            cnt++;
        }
    }
    return cnt;
}
