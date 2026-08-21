class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0, i = 0, j= people.size()-1;
        sort(people.begin(), people.end());
        while(i <= j){
            if(people[i] + people[j] <= limit)  i++;
            ans++;
            j--;
        }
        return ans;

    }
};