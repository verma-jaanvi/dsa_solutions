class Solution {
public:

    int expand(int l, int r, string &s) {

        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }

        return r - l - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {

            // Odd length
            int len1 = expand(i, i, s);

            // Even length
            int len2 = expand(i, i + 1, s);

            int len = max(len1, len2);

            if(len > maxLen) {
                maxLen = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};