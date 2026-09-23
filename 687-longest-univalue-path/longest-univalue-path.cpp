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
    int fn(TreeNode* root, int &ans){
        if(!root)   return 0;

        int l = fn(root->left, ans);
        int r = fn(root->right, ans);

        int lans = 0, rans = 0;
        if(root->left && root->left->val == root->val){
            lans = l + 1;
        }
        if(root->right && root->right->val == root->val){
            rans = r + 1;
        }

        ans = max(ans, rans + lans);

        return max(lans, rans);
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        fn(root, ans);
        return ans;
    }
};