class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int n = s.length();
        string w = "", ans = "";
        for(char ch : s){
            if(ch == ' '){
                ans += w + " ";
                w = "";
            }else
                w = ch + w;
        }
        return ans.substr(0, ans.length()-1);
    }
};