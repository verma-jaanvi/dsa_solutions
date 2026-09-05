class Solution {
public:
    bool fn(int i, int j, int cnt, string &s){
        if(i >= j) return true;

        if(s[i] == s[j])    return fn(i+1, j-1, cnt, s);
        if(s[i] != s[j] && cnt < 1) return fn(i+1, j, 1, s ) | fn(i, j-1, 1, s);

        return false;    
    }

    bool validPalindrome(string s) {
        return fn(0, s.length()-1, 0, s);
    }
};