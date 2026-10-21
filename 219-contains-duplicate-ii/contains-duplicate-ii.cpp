class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int l = 0, r=0;
        for( r = 0; r<n; ++r){
            if(st.count(nums[r]))  return true;

            st.insert(nums[r]);
            if(st.size() > k){
                st.erase(nums[r-k]);
            }
        }
        return false;
    }
};