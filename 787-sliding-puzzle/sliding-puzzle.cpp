class Solution {
public:
    bool iscell(int r, int c){
        if(r < 0 || r > 1 || c < 0 || c > 2)    return false;
        return true;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}};
        string str = "";
        for(int i =0; i<2; ++i){
            for(int j = 0; j<3; ++j){
                str += to_string(board[i][j]);
            }
        }
        string target = "123450";
        if(str == target)   return 0;

        queue<string> q; 
        q.push(str);
        unordered_set<string> vis;
        vis.insert(str);
        vector<vector<int>> nei= {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i< size; ++i){
                string curr = q.front();
                q.pop();

                if(curr == target)  return cnt;
                int idx = curr.find('0');

                for(int nextIdx : nei[idx]){
                    string nextstate = curr;
                    swap(nextstate[idx], nextstate[nextIdx]);

                    if(vis.find(nextstate) == vis.end()){
                        vis.insert(nextstate);
                        q.push(nextstate);
                    }
                }
            }
            cnt ++;
        }
        return -1;
    }
};