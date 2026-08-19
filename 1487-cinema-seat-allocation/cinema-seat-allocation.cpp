class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int ans = n*2;
        unordered_map<int, vector<int>> mpp;
        for(auto vec : rs){
            mpp[vec[0]].push_back(vec[1]);
        }
        for(auto it : mpp){
            bool lt= true, rt = true, mid = true;
            auto vec = it.second;
            for(int i : vec){
                if(i >= 2 && i <= 5)    lt = false;
                if(i >=6 && i <= 9)     rt = false;
                if(i >= 4 && i<= 7)     mid = false;
            }
            if(lt && rt)    continue;
            if(lt || rt || mid) ans--;
            else ans -=2;
        }
        return ans;
    }
};