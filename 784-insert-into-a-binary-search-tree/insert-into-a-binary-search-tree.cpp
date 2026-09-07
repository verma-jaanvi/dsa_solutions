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
    void preorder(TreeNode* root, vector<int> &arr){
        if(!root)   return;
        preorder(root->left, arr);
        arr.push_back(root->val);
        preorder(root->right, arr);
    }

    TreeNode* fn(vector<int> &arr, int st, int en){
        if(st > en)    return NULL;

        int mid = st + (en- st)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = fn(arr, st, mid-1);
        node->right = fn(arr, mid+1, en);

        return node;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int> arr;
        preorder(root, arr);
        arr.push_back(val);
        sort(arr.begin(), arr.end());
        return fn(arr, 0, arr.size()-1);
        //lvl order = left, root, right
        //root at mid
    }
};