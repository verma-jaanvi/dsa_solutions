class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2)  return n;

        int l = 0, ans = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i<n; ++i){
            mpp[fruits[i]]++;
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, (i-l+1));
        }
        return ans;
    }
};