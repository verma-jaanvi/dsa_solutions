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
    int dia = 0;
    
    int diameter(TreeNode* root){
        if(!root)   return 0;
        int lt = 0, rt = 0;
        lt = max(lt, diameter(root->left)) + 1;
        rt = max(rt, diameter(root->right)) +1;
        dia = max(dia, lt+rt+1);
        return max(lt, rt);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        //dfs;
        // if(!root)   return 0;
        diameter(root);
        return dia-3;
    }
};