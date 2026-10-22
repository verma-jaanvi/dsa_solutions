class Solution {
public:
    int countGoodSubstrings(string s) {
        // no repeated char in a string in substring of length 3;
        int n = s.length();
        if(n < 3)   return 0;

        int l = 0;
        int cnt = 0;
        unordered_set<char> st;
        for(int r = 0; r<n; ++r){
            while(st.count(s[r]) && l < r){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            if(r-l+1 > 3){
                st.erase(s[l]);
                l++;
            }

            if(r-l+1 == 3){
                cnt++;
            }
        }
        return cnt;

    }
};