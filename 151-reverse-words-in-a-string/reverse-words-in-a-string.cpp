class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        s+= " ";
        int i = 0;
        while(s[i] == ' ')  i++;

        while(i < s.length()){
            while(isalnum(s[i])){
                word += s[i++];
            }
            ans = " " + word + ans;
            word = "";
            while(s[i] == ' ')  i++;
        }
        return ans.substr(1);
    }
};