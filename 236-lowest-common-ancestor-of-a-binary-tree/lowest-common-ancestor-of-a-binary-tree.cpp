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
    bool fn(TreeNode* root, TreeNode* p, vector<TreeNode*> &path){
        if(!root)   return false;
        
        path.push_back(root);
        if(root == p){
            // path.push_back(p);
            return true;
        }

        if(fn(root->left, p, path) || fn(root->right, p, path)) return true;

        path.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        fn(root, p, path1);
        fn(root, q, path2);

        int len = min(path1.size(), path2.size());

        for(int i = len-1; i>=0; --i){
            if(path1[i] == path2[i])    return path1[i];
        }
        return NULL;
    }
};