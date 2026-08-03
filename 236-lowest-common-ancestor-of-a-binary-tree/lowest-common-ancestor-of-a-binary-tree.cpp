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
    bool fn(TreeNode* root, TreeNode* p, vector<TreeNode*> &p1){
        if(root == NULL)    return false;
        p1.push_back(root);
        if(root == p){
            return true;
        }
        int isLeft = fn(root->left, p, p1);
        int isRight = fn(root->right, p, p1);
        if(isLeft || isRight){
            return true;
        }
        p1.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;

        fn(root, p, p1);
        fn(root, q, p2);
        TreeNode* lca = NULL;
        for(int i=0, j= 0; i < p1.size() && j< p2.size(); i++, j++){
            if(p1[i] != p2[j]){
                return lca;
            }
            lca = p1[i];
        }
        return lca;
    }
};