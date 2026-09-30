class Solution {
public:
    bool isValid(vector<vector<char>> &board, int r, int c, char val){
        for(int i = 0; i<9; ++i){
            if(board[i][c] == val || board[r][i] == val)  return false;
        }
        int sr = r - r%3, sc = c - c%3;
        for(int i = 0; i< 3; ++i){
            for(int j = 0; j<3; ++j){
                if(board[sr + i][sc +j] == val)    return false;
                
            }
            

        }
        return true;
    }

    bool fn(vector<vector<char>>& board) {
        for(int i = 0; i<9; ++i){
            for(int j = 0; j<9; ++j){
                if(board[i][j] == '.'){
                    for(char val = '1'; val<= '9'; ++val){
                        if(isValid(board, i, j, val)){
                            board[i][j] = val;

                            if(fn(board)) return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        fn(board);
    }
};