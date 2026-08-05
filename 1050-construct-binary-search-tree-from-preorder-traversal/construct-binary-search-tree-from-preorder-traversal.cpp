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
int n = 0;

    TreeNode* fn(vector<int>& pre, int &idx, int limit){
        if(idx == n || pre[idx] > limit)    return NULL;
        TreeNode* node = new TreeNode(pre[idx++]);
        
        node->left = fn(pre, idx, node->val);
        
        node->right = fn(pre, idx, limit);
        
        return node;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        int i =0;
        return fn(preorder, i, INT_MAX);
        
    }
};