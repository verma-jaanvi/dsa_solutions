class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans = "";
        int longest = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<char> upper;
                unordered_set<char> lower;

                for (int k = i; k <= j; k++) {
                    if (isupper(s[k])) {
                        upper.insert(tolower(s[k]));
                    } else {
                        lower.insert(s[k]);
                    }
                }
                if (upper == lower) {
                    string temp = s.substr(i, j - i + 1);
                    if (temp.length() > longest) {
                        longest = temp.length();
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};