class Solution {
public:
    bool canplace(vector<int> &nums, int mid, int m){
        int cnt = 1;
        int last = nums[0];
        for(int i = 1; i< nums.size(); ++i){
            if(nums[i] - last >= mid){
                cnt++;
                last = nums[i];
            } 
            if(cnt == m)    return true;
        }
        return false;
    }

    int maxDistance(vector<int>& nums, int m) {
        // if(nums.size() < m) return 
        sort(nums.begin(), nums.end());
        int l = 0 , r = nums[nums.size() - 1] - nums[0], ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            int res = INT_MAX;
            if(canplace(nums, mid, m)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};