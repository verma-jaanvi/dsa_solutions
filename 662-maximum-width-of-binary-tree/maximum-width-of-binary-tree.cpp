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
    int widthOfBinaryTree(TreeNode* root) {
        // bfs + numbering 
        if(!root)   return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            unsigned int min_id = q.front().second;
            unsigned int first = 0, last = 0;
            for(int i =0; i< size; ++i){
                unsigned int curr_id = q.front().second - min_id;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0)  first = curr_id;
                if(i == size - 1)   last = curr_id;
                if(node->left){
                    q.push({node->left, 2*curr_id});

                }
                if(node->right){
                    q.push({node->right, 2*curr_id +1});
                }
            }
            maxWidth = max(maxWidth, (int)(last - first +1));
        }
        return maxWidth;
    }

};