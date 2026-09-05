class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mpp(26, 0);
        if(s.length() != t.length())    return false;
        for(int i = 0; i<s.length(); ++i){
            mpp[s[i] - 'a']++;
            mpp[t[i] - 'a']--; 
        }
        for(int i : mpp){
            if(i != 0)  return false;
        }
        return true;
    }
};