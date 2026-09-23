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
    void fn(TreeNode* root, string &ans, string curr){
        if(!root){
            return;
        }
        curr = curr + char('a' + root->val);

        if(!root->left && !root->right){
            reverse(curr.begin(), curr.end());
            if(ans == "" || curr < ans){
                ans = curr;
            }
            return;
        }

        fn(root->left, ans,  curr);
        fn(root->right, ans,  curr);
        
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        fn(root, ans, "");
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};