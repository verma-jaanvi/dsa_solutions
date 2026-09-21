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
    TreeNode* fn(TreeNode* p, TreeNode* q){

        if(!p)  return q;
        if(!q)  return p;

        p->val += q->val;

        p->left = fn(p->left, q->left);
        p->right = fn(p->right, q->right);

        return p;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return fn(root1, root2);
    }
};