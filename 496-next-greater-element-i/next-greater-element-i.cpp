class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for(int i = 0; i< nums2.size(); ++i){
            mpp[nums2[i]] = i;
        }
        vector<int> ans;
        for(int i : nums1){
            int idx = mpp[i];
            int maxi = i;
            for(int j = idx+1; j<nums2.size(); ++j){
                if(nums2[j] > maxi){
                    maxi = nums2[j];
                    break;
                }
            }
            ans.push_back(maxi > i ? maxi : -1);
        }
        return ans;
    }
};