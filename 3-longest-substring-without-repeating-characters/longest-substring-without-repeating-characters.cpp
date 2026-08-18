class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 1)    return 1;
        unordered_map<char, int> mpp;
        int ans = 0;
        int j = 0;
        for(int i =0; i< len; i++){
            auto it = mpp.find(s[i]);
            if(it != mpp.end() && it->second == 1){
                // ans = max(ans, (i-j));
                while(it->second > 0){
                    mpp[s[j++]]--;
                }
            }
            ans = max(ans, (i-j+1));
            mpp[s[i]]++;
        }
        return ans;
    }
};