class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> ans(len, 0);
        stack<pair<int, int>> st;
        for(int i =len - 1; i>= 0; --i){
            while(!st.empty() && st.top().first <= temp[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i;
            }
            st.push({temp[i], i});
        }
        return ans;
    }
};