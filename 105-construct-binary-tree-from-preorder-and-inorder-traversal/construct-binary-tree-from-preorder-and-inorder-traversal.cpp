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
// int idx = -1;
    TreeNode* build(vector<int> &pre, int preSt, int preEn, vector<int> &in, int inSt, int inEn, map<int, int> &mpp){
        if(preSt > preEn || inSt > inEn)    return NULL;
        TreeNode* root = new TreeNode(pre[preSt]);
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inSt;
        root->left = build(pre, preSt+1, preSt + numsLeft, in, inSt, inRoot - 1, mpp);
        root->right = build(pre, preSt + numsLeft + 1, preEn, in, inRoot+1, inEn, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for(int i=0; i< inorder.size(); ++i){
            mpp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
    }
};