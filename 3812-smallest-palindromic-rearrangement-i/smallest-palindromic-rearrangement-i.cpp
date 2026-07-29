class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string t = "";
        if(n&1){
            t = s.substr(0, n/2);
            sort(t.begin(), t.end());
            t+= s[n/2];
            t += s.substr(n/2+1);
            sort(t.begin() + n/2+1, t.end(), greater<int>());
        }else{
            t = s.substr(0, n/2);  
            sort(t.begin(), t.end());
            t += s.substr(n/2);
            sort(t.begin() + n/2, t.end(), greater<int>());       
        }
        
        return t;

    }
};