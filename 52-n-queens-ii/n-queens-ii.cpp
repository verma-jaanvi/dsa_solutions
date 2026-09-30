class Solution {
public:

    bool isValid(vector<string> &curr, int &row, int &col, int &n){
        for(int i = 0; i< row; ++i){
            if(curr[i][col] == 'Q') return false;
        }

        for(int i = row - 1, j = col -1; i>= 0 && j >= 0; --i, --j){
            if(curr[i][j] == 'Q')   return false;
        }

        for(int i = row - 1, j = col +1; i>= 0 && j < n; --i, ++j){
            if(curr[i][j] == 'Q')   return false;
        }
        return true;
    }

    void fn(int idx, int &n, int &cnt, vector<string> curr){
        if(idx == n){
            cnt++;
            return;
        }
        for(int i = 0; i<n; ++i){
            if(isValid(curr, idx, i, n)){
                curr[idx][i] = 'Q';
                fn(idx+1, n, cnt, curr);
                curr[idx][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> curr;
        
        for(int i = 0; i<n; ++i){
            string s = "";
            for(int j = 0; j<n; ++j){
                s += '.';
            }
            curr.push_back(s);
        }

        int cnt = 0;
        fn(0, n, cnt, curr);
        return cnt;
    }
};