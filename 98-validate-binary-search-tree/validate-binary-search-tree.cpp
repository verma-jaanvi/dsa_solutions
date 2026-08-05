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
    bool fn(TreeNode* root, long long minlimit, long long maxlimit){
        if(!root)   return true;
        if(root->val >= maxlimit || root->val <= minlimit)      return false;

        // if(root->left){
            // if(root->left->val < root->val){
            //     return fn(root->left, minlimit,  root->val);
            // }else{
            //     return false;
            // }
        // }

        // if(root->right){
            // if(root->right->val > root->val){
            //     return fn(root->right, root->val, maxlimit);
            // }else{
            //     return false;
            // }
        // }

        return fn(root->left, minlimit,  root->val) &&  fn(root->right, root->val, maxlimit);
        // return true;

    }

    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        return fn(root, LLONG_MIN, LLONG_MAX);
        
    }
};