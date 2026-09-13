class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int l1 = s1.length(), l2 = s2.length();
        if(l2 < l1) return false;

        for(int i = 0; i<l1; ++i){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2)  return true;

        for(int i = l1; i < l2; ++i){
            freq2[s2[i] - 'a']++;
            freq2[s2[i- l1] - 'a']--;
            
            if(freq1 == freq2)  return true;
        }
        return false;
    }
};