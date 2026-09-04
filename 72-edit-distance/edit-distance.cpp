class Solution {
public:
    int fn(int i, int j, string &w1, string &w2, vector<vector<int>> &dp){
        if(i < 0)   return j+1;
        if(j < 0)   return i+1;
        if(dp[i][j] != -1)  return dp[i][j];

        int t = INT_MAX, nt = INT_MAX;
        if(w1[i] == w2[j])  t = fn(i-1, j-1, w1, w2, dp);
        else{
            nt = 1 + min(fn(i, j-1, w1, w2, dp), min(fn(i-1, j, w1, w2, dp), fn(i-1, j-1, w1, w2, dp)));
        }
        
        return dp[i][j] = min(t, nt);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(n-1, m-1, word1, word2, dp);
    }
};