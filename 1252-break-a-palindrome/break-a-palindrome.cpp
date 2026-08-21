class Solution {
public:
    string breakPalindrome(string str) {
        if (str.length() == 1) {
            return "";
        }
        int n = str.length();
        for (int i = 0; i < n / 2; i++) {
            if (str[i] != 'a') {
                str[i] = 'a';
                return str;
            }
        }
        str[n - 1] = 'b';
        return str;
    }
};