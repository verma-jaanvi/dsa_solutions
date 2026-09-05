class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> pref;
        pref[0] = 1;
        long long sum = 0;

        int ans = 0;
        for(int i = 0; i<nums.size(); ++i){
            sum += nums[i];
            if(pref.find(sum - k) != pref.end())   ans += pref[sum - k];
            pref[sum]++;
        }
        return ans;
    }
};