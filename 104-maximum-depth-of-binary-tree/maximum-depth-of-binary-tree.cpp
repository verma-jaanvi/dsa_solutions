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
    int fn(TreeNode* root, int &maxi){
        if(!root->left && !root->right) return 0;
        
        int l = 0, r = 0;
        if(root->left)  l = 1 + fn(root->left, maxi);
        if(root->right) r = 1 + fn(root->right, maxi);

        return maxi = max(l, r);
    }

    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        int maxi = 0;
        return fn(root, maxi) + 1;
    }
};