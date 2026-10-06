class Solution {
public:
    bool fn(int i, int sidx, int tidx, string &s, string &t, string &match, vector<vector<int>> &dp){
        if(i == match.length()){
            if(sidx == s.length() && tidx == t.length())
                return true;
            return false;
        }

        if(dp[sidx][tidx] != -1)    return dp[sidx][tidx];    

        if(match[i] == s[sidx]){
            if(fn(i+1, sidx+1, tidx, s, t, match, dp)){
                return dp[sidx][tidx] = true;
            }
        } 
        if(match[i] == t[tidx]){
            if(fn(i+1, sidx, tidx+1, s, t, match, dp)){
                return dp[sidx][tidx] = true;
            }
        }
        return dp[sidx][tidx] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() > s3.length()) return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return fn(0, 0, 0, s1, s2, s3, dp);
    }
};