#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int i, int j, int p, int k, vector<int>& stones, const vector<int>& pref, vector<vector<vector<int>>>& dp) {
        if (i == j) {
            return (p == 1) ? 0 : 1e9;
        }

        if (dp[i][j][p] != -1) {
            return dp[i][j][p];
        }

        if (p == 1) {
            int subcost = fn(i, j, k, k, stones, pref, dp);
            if (subcost >= 1e9) return dp[i][j][p] = 1e9;
            int sum = (i == 0) ? pref[j] : pref[j] - pref[i - 1];
            return dp[i][j][p] = subcost + sum;
        }

        int ans = 1e9;
        for (int mid = i; mid < j; mid += k - 1) {
            int leftCost = fn(i, mid, 1, k, stones, pref, dp);
            int rightCost = fn(mid + 1, j, p - 1, k, stones, pref, dp);
            if (leftCost < 1e9 && rightCost < 1e9) {
                ans = min(ans, leftCost + rightCost);
            }
        }
        return dp[i][j][p] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        vector<int> pref;
        int sum = 0;
        for (int i : stones) {
            sum += i;
            pref.push_back(sum);
        }

        return fn(0, n - 1, 1, k, stones, pref, dp);
    }
};