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
    void fn(TreeNode* root, int target, vector<vector<int>>& ans,
            vector<int>& curr) {
        if (!root) {
            return;
        }
        curr.push_back(root->val);

        if(!root->left && !root->right && target == root->val){
            ans.push_back(curr);
        }

        fn(root->left, target - root->val, ans, curr);
        fn(root->right, target - root->val, ans, curr);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        fn(root, targetSum, ans, curr);
        return ans;
    }
};