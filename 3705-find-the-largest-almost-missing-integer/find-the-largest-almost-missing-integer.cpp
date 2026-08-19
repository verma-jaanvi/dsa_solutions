class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        
        int n = nums.size();
        for(int i =0 ; i<=n -k; ++i){
            unordered_set<int> st;
            for(int j = i; j<i+k ; ++j){
                st.insert(nums[j]);
            }
            for(int j : st){
                mpp[j]++;
            }
        }
        int ans = -1;
        for(auto &it : mpp){
            if(it.second == 1){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};