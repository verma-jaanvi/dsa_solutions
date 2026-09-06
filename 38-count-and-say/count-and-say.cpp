class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i<=n; ++i){
            string word = "";
            int cnt = 0;
            char w = s[0];
            for(char ch: s){
                if(ch == w ){
                    cnt++;
                    continue;
                }else{
                    word += to_string(cnt) + w;
                    w = ch;
                    cnt = 1;
                }
            }
            word += to_string(cnt) + w;
            s = word;
        }
        return s;
    }
};