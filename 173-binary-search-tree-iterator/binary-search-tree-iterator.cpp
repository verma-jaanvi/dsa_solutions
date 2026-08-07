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
class BSTIterator {
    TreeNode* root = NULL;
    // TreeNode* curr = NULL;
    int i = 0;
    vector<TreeNode*> vec;
    void inorder(TreeNode* root){
        if(!root){  
            // vec.push_back(NULL); 
            return;
        }
        if(root->left)  inorder(root->left);
        vec.push_back(root);
        if(root->right) inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder(root);
    }
    
    int next() {
        int val = vec[i]->val;
        i++;
        return  val;
    }
    
    bool hasNext() {
        
        if(i < vec.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */