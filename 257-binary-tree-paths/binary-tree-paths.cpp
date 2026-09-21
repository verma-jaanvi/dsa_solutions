/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fn(TreeNode* root, vector<string> &ans, string curr){
        curr = curr == "" ? to_string(root->val) :  curr + "->" + to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(curr);
            return;
        }

        if(root->left)
            fn(root->left, ans, curr);
        if(root->right)
            fn(root->right, ans, curr );
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        fn(root, ans, "");
        return ans;
    }
};