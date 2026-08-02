/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs + null
        if(!root)   return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        map<int, vector<int>> mpp;

        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();

            mpp[lvl].push_back(curr->val);
            if (curr->left) {
                q.push({curr->left, lvl + 1});
            }
            if (curr->right) {
                q.push({curr->right, lvl + 1});
            }
        }
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};