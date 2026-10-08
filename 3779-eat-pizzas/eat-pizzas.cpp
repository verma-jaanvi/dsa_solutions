class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int c=n/4;
        // int day = 1;
        int r = n-1;
        long long ans = 0;
        int odd = (c + 1)/2;
        int even = c- odd;
        for(int i = 0; i<odd; i++){
            
                ans += pizzas[r];
                r--;

        }
        for(int i = 0; i< even; ++i){
            r--;
                ans += pizzas[r];
            r--;
        }
        return ans;
    }
};