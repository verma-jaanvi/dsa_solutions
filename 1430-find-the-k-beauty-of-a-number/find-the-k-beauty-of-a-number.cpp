class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int l = 0;
        string val = to_string(num);
        int n = val.length(), cnt = 0;
        while(l <= n-k){
            int div = stoi(val.substr(l, k));
            cout << div << " ";
            if(div != 0 && num % div == 0){
                cnt++;
            }
            l++;
        }
        return cnt;
    }
};