/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fn(vector<int>& post, int postSt, int postEn, vector<int>& in,
                 int inSt, int inEn, map<int, int>& mpp) {
        if (postSt > postEn || inSt > inEn)
            return NULL;

        TreeNode* root = new TreeNode(post[postEn]);
        int inRoot = mpp[root->val];
        int leftLen = inRoot - inSt;

        root->left =
            fn(post, postSt, postSt + leftLen - 1, in, inSt, inRoot - 1, mpp);

        root->right =
            fn(post, postSt + leftLen, postEn - 1, in, inRoot + 1, inEn, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); ++i) {
            mpp[inorder[i]] = i;
        }
        return fn(postorder, 0, postorder.size() - 1, inorder, 0,
                  inorder.size(), mpp);
    }
};