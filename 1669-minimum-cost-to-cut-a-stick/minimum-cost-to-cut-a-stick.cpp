class Solution {
public:
    int fn(int st, int en, vector<int> &cuts, vector<vector<int>> &dp ){
        if(en - st <= 1)    return 0;

        if(dp[st][en] != -1)    return dp[st][en];
        int cost = INT_MAX;
        for(int i = st+1; i< en; ++i){
            int curr = cuts[en]-cuts[st] + fn(st, i, cuts, dp) + fn(i, en, cuts, dp);
            cost = min(cost, curr);
        }
        return dp[st][en] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        return fn(0, cuts.size()-1, cuts, dp);
    }
};