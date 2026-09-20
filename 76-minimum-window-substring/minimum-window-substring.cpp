class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length(); int tlen = t.length();
        if(tlen > slen) return "";
        if(tlen == 0)   return "";
        unordered_map<char, int> words;
        for(int i=0;i<tlen;i++){
            words[t[i]]++;
        }
        unordered_map<char, int> seen;
        // for(const auto& [key, value] : words){
        //     seen[key] = 0;
        // }
        string ans =""; int cnt = 0;
        int l =0; int len = INT_MAX;
        int required = words.size();
        int startIdx = 0;

        for(int i=0;i< slen; i++){
            char ch = s[i];
            seen[ch]++;
            if(words.count(ch) && seen[ch] == words[ch]){
                cnt++;
            } 
            while(cnt == required){
                if(len > i-l+1){
                    startIdx = l;
                    len= i-l+1;
                }
                char w =s[l];
                seen[w]--; 
                if(words[w] && seen[w] < words[w]){
                    cnt--;
                }
                l++;    
            }
            
        }
        if (len == INT_MAX) {
            return "";
        } else {
            return s.substr(startIdx, len);
        }
    }
};