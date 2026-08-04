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
    bool fn(TreeNode* l, TreeNode* r){
        if(!l && !r)    return true;
        if(!l || !r)    return false;
        if(l->val != r->val)    return false;

        return (fn(l->left, r->right) && fn(l->right , r->left));
        // return true;
    }

    bool isSymmetric(TreeNode* root) {
        return fn(root->left, root->right);
    }
};