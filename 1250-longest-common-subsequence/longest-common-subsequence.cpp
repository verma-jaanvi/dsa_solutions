class Solution {
public:

    int fn(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0)    return 0;

        if(dp[idx1][idx2] != -1)    return dp[idx1][idx2];
        int m = -1e9, nt = -1e9;
        if(text1[idx1]== text2[idx2])   m = 1 + fn(idx1-1, idx2-1, text1, text2, dp);
        else    nt = max(fn(idx1-1, idx2, text1, text2, dp), fn(idx1, idx2-1, text1, text2, dp));

        return dp[idx1][idx2] = max(m, nt); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return fn(text1.size()-1, text2.size()-1, text1, text2, dp);
    }
};