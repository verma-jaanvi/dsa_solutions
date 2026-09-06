class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        int idx = -1;
        for(int i = 0; i<s.length(); ++i){
            mpp[s[i]]++;
        }
        
        for(auto it : mpp){
            if(it.second == 1){
                if(idx == -1)   idx = s.find(it.first);
                else idx = min(idx, (int)s.find(it.first));
            } 
        }
        return idx;
    }
};