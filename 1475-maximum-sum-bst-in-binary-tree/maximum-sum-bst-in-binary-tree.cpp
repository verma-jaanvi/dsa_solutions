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
    struct NodeInfo{
        bool isbst;
        int sum;
        int minval;
        int maxval;
    };

    int maxi =0;

public:
    NodeInfo fn(TreeNode* root){
        if(!root){   
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        NodeInfo l = fn(root->left);
        NodeInfo r = fn(root->right);
        
        if(l.isbst && r.isbst && root->val > l.maxval && root->val < r.minval){
            int currsum = root->val + l.sum + r.sum;
            maxi = max(currsum, maxi);

            return{
                true, 
                currsum,
                min(root->val, l.minval),
                max(root->val, r.maxval)
            };

        }
        return {false, 0, 0, 0};

    }

    int maxSumBST(TreeNode* root) {
        maxi = 0;
        fn(root);
        return maxi;
    }
};