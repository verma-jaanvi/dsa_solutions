class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //start 
        int n = gas.size();
        int st = 0;
        int ans = 0, cos = 0, fuel = 0;
        for(int i=0; i< n; ++i){
            cos += cost[i]; fuel += gas[i];
            ans += gas[i] - cost[i];
            if(ans < 0){
                ans = 0;
                st = i+1;
            }
        }
        if(cos > fuel)  return -1;
        return st;
    }
};