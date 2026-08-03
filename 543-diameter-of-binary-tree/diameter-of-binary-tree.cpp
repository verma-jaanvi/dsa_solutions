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
    int maxdia = 0;

    int height(TreeNode* root){
        if(root == NULL)   return 0;
        int lht = height(root->left);
        int rht = height(root->right);
        maxdia = max(maxdia, lht+rht);
        return 1 + max(lht, rht);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // dfs + bfs
        
        // longest path on left + longest path on right from same parent node 
        height(root);
        return maxdia;
    }
};