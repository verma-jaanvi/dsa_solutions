class Solution {
public:
    int sum(unordered_map<int, int> mpp, int x){
        int sum = 0;
        vector<pair<int, int>> vec;
        for(auto [key, val] : mpp){
            vec.push_back({key, val});
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.second == b.second)    return a.first > b.first;
            return a.second > b.second;
        });
        int mini =  min(x, (int)vec.size());
        for(int i = 0; i< mini; ++i){
            sum += vec[i].second * vec[i].first;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        int l = 0;
        unordered_map<int, int> mpp;
        for(int r = 0; r<k; ++r){
            mpp[nums[r]]++;
        }
        ans.push_back(sum(mpp, x));
        for(int r = k; r<n; ++r){
            if(l < r-k+1){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(mpp[nums[l]]);
                l++;
            }
            mpp[nums[r]]++;
            ans.push_back(sum(mpp, x));
        }
        return ans;
    }
};