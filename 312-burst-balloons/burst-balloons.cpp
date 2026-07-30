typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    int fn(vvi &dp, vi &nums, int left, int right){
        if(left+1 == right)  return 0;
        if(dp[left][right] != -1)  return dp[left][right];
        int maxi =0;
        for(int i = left+1; i< right ; ++i){
            int c = nums[left] * nums[i] * nums[right]
                    + fn(dp, nums, left, i)
                    + fn(dp, nums, i, right);
            maxi = max(maxi, c);
            
        }
        return dp[left][right] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        vi vec = {1};
        for(int i : nums)   vec.push_back(i);
        vec.push_back(1);
        int n = vec.size();
        vvi dp(n, vi(n, -1));
        // vi used(n, 0);
        return fn(dp, vec, 0, n-1);

    }
};