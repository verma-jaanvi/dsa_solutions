/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)   return {};
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> lvl;

        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            if(node){
                vector<Node*> ch = node->children;
                lvl.push_back(node->val);
                
                for(Node* it : ch){
                    q.push(it);
                }
            }else{
                ans.push_back(lvl);
                lvl = {};
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};