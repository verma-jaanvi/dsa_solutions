class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string ans = num, curr = num;
        int l = 0;
        int n = num.length();
        for(int r = 0; r<n; ++r){
            if((curr[r] - '0') <= change[curr[r] - '0']){
                curr[r] = change[curr[r] - '0'] + '0';
                ans = ans < curr ? curr : ans;
            }else{
                curr = num;
                l = r;
            }
        }
        return ans;
    }
};