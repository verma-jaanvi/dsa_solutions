class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int group = 1;
        int g_speed = speed[n-1];
        for(int i = n-2; i>=0; --i){
            if(position[i+1] - position[i] <= distance){
                continue;
            }
            else if(speed[i] <= g_speed){
                group++;
                g_speed = speed[i];
            }
        }
        return group;
    }
};