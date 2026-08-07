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
    void inorder(TreeNode* root, vector<int> &vec){
        if(!root)   return;
        if(root->left)  inorder(root->left, vec);
        vec.push_back(root->val);
        if(root->right) inorder(root->right, vec);
    }

    TreeNode* buildTree(vector<int> &nums, int st, int en){
        if(st > en)  return NULL;

        int mid = st + (en - st)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, st, mid-1);
        node->right = buildTree(nums, mid+1, en);
        
        return node;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // get its inorder o(n)
        // add val and sort the element o(nlogn)
        // then build the tree again o(n) 
        // total o(2n + nlogn)
        vector<int> vec;
        inorder(root, vec);
        vec.push_back(val);
        sort(vec.begin(), vec.end());
        return buildTree(vec, 0, vec.size()-1);
        
    }
};