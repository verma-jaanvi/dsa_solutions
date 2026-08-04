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
int maxi = INT_MIN;
    int fn(TreeNode* root){
        if(!root)   return 0;
        int l = max(0, fn(root->left));
        int r = max(0, fn(root->right));
        maxi = max(maxi, l+r+root->val);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        fn(root);
        return maxi;
    }
};