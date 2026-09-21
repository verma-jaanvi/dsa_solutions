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
    bool fn(TreeNode* root, int target){
        // if(target == 0) return true;
        // if(target < 0)  return false;
        if(!root)   return false;

        if(!root->left && !root->right){
            return target == root->val;
        }

        bool lft = fn(root->left, target - root->val);
        bool rft =  fn(root->right, target - root->val);
        
        return lft | rft;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)   return false;
        return fn(root, targetSum);
    }
};