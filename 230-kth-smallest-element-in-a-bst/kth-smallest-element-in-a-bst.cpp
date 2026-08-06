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
    // inorder
    int count = 0;
    int ans = -1;
    void fn(TreeNode* root, int k) {
        if(!root)   return;
        
        fn(root->left, k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        if(count < k){
          fn(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        fn(root, k);
        return ans;
    }
};