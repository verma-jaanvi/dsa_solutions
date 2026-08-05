/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool fn(TreeNode* root, TreeNode* node, vector<TreeNode*> &vec){
        if(root == NULL)    return false;

        vec.push_back(root);
        if(root == node){
            return true;
        }
        
        if(fn(root->left, node, vec))   return true;

        if(fn(root->right, node, vec)) return true;
        vec.pop_back();

        return false;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;
        fn(root, p, p1);
        fn(root, q, p2);
        TreeNode* ans = NULL;
        int len = min(p1.size() , p2.size());
        for(int i=0; i< len; ++i){
            if(p1[i] == p2[i]){
                ans = p1[i];
            }else   break;
        }
        return ans;
    }
};