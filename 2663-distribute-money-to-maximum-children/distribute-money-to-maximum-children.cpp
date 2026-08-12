class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int ans = money / 7;
        int left = money % 7;
        if (ans == children && left > 0) {
            return children - 1;
        }
        
        if (ans > children) {
            return children - 1;
        }

        if (left == 3 && (children - ans) == 1) {
            return ans - 1;
        }

        return ans;
    }
};