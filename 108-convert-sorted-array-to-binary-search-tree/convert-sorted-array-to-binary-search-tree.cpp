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
    TreeNode* fn(vector<int>& nums, int st, int en){
        if(st > en)    return NULL;
        int mid = st + (en-st)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = fn(nums, st, mid-1);
        curr->right = fn(nums, mid+1, en);
        return curr;
        
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())    return NULL;
        int n = nums.size();
        // int mid = n/2;
        // TreeNode* root = new TreeNode(nums[mid]);
        return fn(nums, 0, n-1);
        // fn(root, mid+1, n-1);
        // return root;

    }
};