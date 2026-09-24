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
    TreeNode* fn(int prest, int preen, int postst, int posten, vector<int>& preorder, vector<int>& postorder, unordered_map<int, int> &mpp){
        if(prest > preen || postst > posten)    return NULL;

        TreeNode* node = new TreeNode(preorder[prest]);

        if(prest == preen)  return node;

        int val = preorder[prest+1];
        int mid = mpp[val];

        int len = mid - postst + 1;

        node->left = fn(
            prest + 1,
            prest + len,
            postst,
            mid,
            preorder,
            postorder,
            mpp
        );

        node->right = fn(
            prest + len + 1,
            preen,
            mid + 1,
            posten - 1,
            preorder,
            postorder,
            mpp
        );

        return node;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // preorder root left right
        // postorder left right root

        unordered_map<int, int> mpp;
        int n = preorder.size();
        for(int i = 0; i<n; ++i){
            mpp[postorder[i]] = i;
        }

        return fn(0, n-1, 0, n-1, preorder, postorder, mpp);
    }
};