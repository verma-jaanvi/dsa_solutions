class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas = 0, tcost = 0, currtank = 0, st = 0;

        for(int i=0; i< gas.size(); ++i){
            tgas +=gas[i]; 
            tcost += cost[i];
            currtank += gas[i] - cost[i];
            if(currtank < 0){
                st = i+1;
                currtank = 0;
            }
        }
        if(tgas < tcost)    return -1;
        return st;
    }
};