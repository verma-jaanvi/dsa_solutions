class Solution {
public:
    bool isValid(vector<string> &curr, int row, int col, int &n){
        if(curr.empty()){
            return true;
        }
        for(int i = 0; i< row; ++i){
            if(curr[i][col] == 'Q') return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(curr[i][j] == 'Q') return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(curr[i][j] == 'Q')   return false;
        }

        return true;
    }

    void fn(int i, int &n, vector<vector<string>> &ans, vector<string> curr){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        string s = "";
        for(int idx = 0; idx<n; ++idx)    s += ".";
        for(int col = 0; col < n; col++){
            if(isValid(curr, i, col, n)){
                s[col] = 'Q';
                curr.push_back(s);
                fn(i+1, n, ans, curr);
                s[col] = '.';
                curr.pop_back();
            } 
        }      
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        fn(0, n, ans, curr);
        return ans;
    }
};