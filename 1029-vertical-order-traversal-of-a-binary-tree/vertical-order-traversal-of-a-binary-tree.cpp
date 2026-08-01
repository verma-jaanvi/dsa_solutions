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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        map<pair<int, int>, vector<int>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); 
        // int level = 0;

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;

            q.pop();
            mpp[{hd, lvl}].push_back(curr->val);
            if (curr->left != NULL) {
                q.push({curr->left, {hd - 1, lvl + 1}});
            }
            if (curr->right != NULL) {
                q.push({curr->right, {hd + 1, lvl + 1}});
            }
        }
        // sort(mpp.begin(), mpp.end())
        vector<vector<int>> ans;
        int last_hd = -100000;

        for (auto it : mpp) {
            sort(it.second.begin(), it.second.end());
            int current_hd = it.first.first;
            if(ans.empty() || current_hd != last_hd){
                ans.push_back(it.second);
                last_hd = current_hd;
            }else{
                ans.back().insert(ans.back().end(), it.second.begin(), it.second.end());
            }
            // ans.push_back(it.second);
        }
        return ans;
    }
    
};