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
bool ans = true;

    int fn(TreeNode* root){
        if(root == NULL)    return 0;
        int lht = fn(root->left);
        int rht = fn(root->right);

        if(abs(lht-rht)>1){
            ans = false;
            // return 0;
        }
        return 1+ max(rht, lht);
    }

    bool isBalanced(TreeNode* root) {
        
        fn(root);
        return ans;
    }
};