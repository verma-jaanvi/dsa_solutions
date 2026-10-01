class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        double area = 0;
        int x1 = points[0][0], x2 = points[1][0], x3 = points[2][0];
        int y1 = points[0][1], y2 = points[1][1], y3 = points[2][1];

        area = (x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.0;
        return area != 0;
    }
};