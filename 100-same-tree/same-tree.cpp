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
    void fn(TreeNode* root, vector<string> &ans){
        if(!root){ 
            ans.push_back("null");
            return;
        }
        ans.push_back(to_string(root->val));
        fn(root->left, ans);
        fn(root->right, ans);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> p1, p2;
        fn(p, p1);  fn(q, p2);
        for(int i =0, j=0; i< p1.size() && j < p2.size(); ++i, ++j){
            if(p1[i] != p2[j])  return false;
        }
        return true;
    }
};