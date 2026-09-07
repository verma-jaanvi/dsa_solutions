class Solution {
public:
    bool fn(vector<string>& dict, vector<int> &dp, string &s, int idx){
        if(idx == s.length())   return true;
        if(dp[idx] != -1)   return dp[idx];
        for(string word : dict){
            int len = word.size();
            if(idx+len <= s.length() && s.substr(idx, len) == word){
                if(fn(dict, dp, s, idx+len)){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n, -1);
        return fn(wordDict, dp, s, 0);
    }
};