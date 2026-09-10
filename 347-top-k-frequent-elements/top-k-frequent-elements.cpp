class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        vector<pair<int, int>> ans;
        for(auto i: mpp){
            ans.push_back({i.second, i.first});
        }

        sort(ans.begin(), ans.end());
        vector<int> res;
        int n = ans.size();
        for(int i = n-1; i>= n-k; --i){
            res.push_back( ans[i].second);
        }
        return res;
    }
};