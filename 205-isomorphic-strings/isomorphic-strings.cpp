class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())    return false;
        unordered_map<char, char> mpp;
        unordered_map<char, char> mppt;
        for(int i = 0; i<s.length(); ++i){
            if(mpp.count(s[i]) && mpp[s[i]] != t[i])    return false;
            if(mppt.count(t[i]) && mppt[t[i]] != s[i])  return false; 
            mpp[s[i]] = t[i];
            mppt[t[i]] = s[i];
        }
        return true;
    }
};