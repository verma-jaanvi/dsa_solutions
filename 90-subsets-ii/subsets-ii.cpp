class Solution {
public:
    void fn(vector<vector<int>> &ans, vector<int> &arr, vector<int> curr, int i){
        ans.push_back(curr);

        for(int idx = i; idx < arr.size(); idx++){
            if(idx > i && arr[idx] == arr[idx -1])   continue;
            curr.push_back(arr[idx]);
            fn(ans, arr, curr, idx+1);
            curr.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        fn(ans, nums, {}, 0);
        return ans;
    }
};