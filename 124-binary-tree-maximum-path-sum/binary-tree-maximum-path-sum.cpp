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
        if(!root)   return 0;
        int lt = 0, rt = 0;
        lt = max(lt, fn(root->left, maxi));
        rt = max(rt, fn(root->right, maxi));
        maxi = max(maxi, lt+rt+root->val);
        return root->val + max(lt, rt);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        fn(root, maxi);
        return maxi;
    }
};