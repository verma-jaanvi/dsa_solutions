class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, ans = 0, maxfreq = 0;
        for(int r = 0; r< s.length(); ++r){
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            if((r-l+1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};