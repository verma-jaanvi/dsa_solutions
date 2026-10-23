class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mpp;
        int l = 0, ans = 0;
        for(int r=0; r<n; ++r){
            mpp[s[r]]++;
            while(l < r && mpp['0'] > k && mpp['1'] > k){
                mpp[s[l]]--;
                l++;
            }
            ans += r-l+1;

        }

        return ans;
    }
};