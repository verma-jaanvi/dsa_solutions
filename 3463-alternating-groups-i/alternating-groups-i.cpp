class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        // fixed size
        int l = 1;
        int ans = 0;
        while(l < n-1){
            if(colors[l] != colors[l-1] && colors[l] != colors[l+1]){
                ans++;
            }
            l++;
        }
        if(colors[0] != colors[n-1] && colors[0] != colors[1])  ans++;
        if(colors[n-1] != colors[0] && colors[n-1] != colors[n-2])  ans++;
        return ans;
    }
};