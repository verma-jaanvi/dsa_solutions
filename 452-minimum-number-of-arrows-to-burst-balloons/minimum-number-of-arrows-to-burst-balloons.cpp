class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end());
        int end = points[0][1]; //recent end
        for(int i =1; i< points.size(); ++i){
            if(points[i][0] > end){
                ans++;
                end = points[i][1];
            }else{
                end = min(end, points[i][1]);
            }
        }
        return ans;

    }
};