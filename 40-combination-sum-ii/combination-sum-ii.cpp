class Solution {
public:
    void fn(vector<int>& arr, vector<vector<int>>& ans, vector<int> curr,
            int tar, int i) {
        if (tar == 0) {
            ans.push_back(curr);
            return;
        }

        for(int idx= i; idx< arr.size(); ++idx){
            if(idx > i && arr[idx] == arr[idx -1])   continue;
            if(tar >= arr[idx]){
                curr.push_back(arr[idx]);
                fn(arr, ans, curr, tar - arr[idx], idx+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        fn(arr, ans, {}, target, 0);
        return ans;
    }
};