class Solution {
public:
    bool isValid(vector<vector<int>>& graph, int &node, int &cl, vector<int> &ans){
        for(int i : graph[node]){
            if(ans[i-1] == cl)  return false;
        }
        return true;
    }

    bool fn(int node, int &n, vector<vector<int>>& graph, vector<int>& ans) {
        if(node == n+1){
            return true;
        }
        for(int i = 1; i<=4; ++i){
            if(isValid(graph, node, i, ans)){
                ans[node-1] = i;
                if(fn(node+1, n, graph, ans)){
                    return true;
                } 
                ans[node-1] = 0;
            }
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector< int>> graph(n+1);
        for (int i = 0; i < paths.size(); ++i) {
            int u = paths[i][0], v = paths[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // vector<int> color = {0, 1, 2, 3, 4};
        vector<int> ans(n, 0);
        fn(1, n, graph, ans);
        return ans;
    }
};