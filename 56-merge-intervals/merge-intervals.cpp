class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto i : intervals){
            if(!ans.empty()){
                int en = ans.back()[1];
                if(en >= i[0]){  
                    ans.back()[1] = max(ans.back()[1], i[1]);
                    continue;
                }
            }
            ans.push_back(i);
        }
        return ans;
    }
};