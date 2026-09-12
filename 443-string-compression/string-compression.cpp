class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0, j = 0;
        while(j < chars.size()){
            while(j< chars.size() && chars[i] == chars[j]){
                j++;
            }
            if(j == i +1){
                s += chars[i];
            }else{
                s += chars[i] + to_string(j-i);
            }
            i = j;
        }
        for(int k = 0; k< s.length(); k++){
            chars[k] = s[k];
        }
        return s.length();
    }
};