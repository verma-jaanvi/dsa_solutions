/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // TreeNode* fn(TreeNode* root, int val, string& s, int st, int en) {
    //     if (st > en)
    //         return NULL;
    //     // TreeNode* root;
    //     // int val = 0;
    //     int idx = st;
    //     char ch = s[st];
    //     if (ch == '#') {
    //         TreeNode* node = new TreeNode(val);
    //         node->left = fn(node, val, s, st+idx, en);
    //         node->right = fn(node, val, s, );
    //     } else if (ch == 'n') {
    //         return NULL;
    //     } else {
    //         val += ch - '0';
    //     }

    //     return root;
    // }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        string ser = "";
        queue<TreeNode*> q;
        q.push(root);
        // q.push(NULL);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                ser += to_string(curr->val) + "#";
                
                q.push(curr->left);
                q.push(curr->right);
            } else {
                ser += "n#";
            }
        }
        // cout << ser;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())    return NULL;
        stringstream s(data);
        string str;
        getline(s, str, '#');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(s, str, '#');
            if(str != "n"){
                TreeNode* leftnode = new TreeNode(stoi(str));
                curr->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, '#');
            if(str != "n"){
                TreeNode* rightnode = new TreeNode(stoi(str));
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));