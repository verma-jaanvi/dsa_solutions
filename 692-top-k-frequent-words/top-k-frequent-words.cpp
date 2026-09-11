class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(string i : words){
            mpp[i]++;
        }
        vector<pair<string, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
            
        });
        vector<string> ans;
        for(int i = 0; i<k; ++i){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};