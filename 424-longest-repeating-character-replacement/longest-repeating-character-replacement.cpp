class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt = 0, i = 0;
        int n = s.length();
        int ans = 0;
        vector<int> freq(26, 0);
        // unordered_map<char, int> mpp;
        for(int j = 0; j< n; ++j){
            freq[s[j] - 'A']++;
            cnt = max(cnt, freq[s[j] - 'A']);

            while((j-i+1) - cnt > k){
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, (j-i+1));
        }
        return ans;
    }
};