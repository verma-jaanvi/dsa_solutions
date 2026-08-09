class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> deg(numCourses, 0);

        int n = prerequisites.size();
        for(int i= 0; i<n; ++i){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            deg[u]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(deg[i] == 0) q.push(i);
        }
        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int n : adj[node]){
                deg[n]--;
                if(deg[n] == 0) q.push(n);
            }
        }
        return count == numCourses;

    }
};