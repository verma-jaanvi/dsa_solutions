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
// hashset + dfs
    bool dfs(TreeNode* root, int k, vector<int> &vec){
        if(!root)   return false;

        int key = root->val;
        if(find(vec.begin(), vec.end(), k-key) != vec.end()){
            return true;
        }

        vec.push_back(key);
        return dfs(root->right, k, vec) || dfs(root->left, k, vec);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> vec;
        return dfs(root, k, vec);
    }
};