/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        map<int, Node*> mpp;
        // vector<bool>    vis(101, false);
        queue<Node*> q;
        Node* root = new Node(node->val);
        // vis[node->val] = true;

        // vector<Node*> l = node->neighbors;
        // for(Node* n : l){
        //     q.push(n);
        // }
        mpp[node->val] = root;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            // Node* nnode = new Node(curr->val);
            // mpp[curr->val] = nnode;
            // vis[curr->val] = true;
            vector<Node*> neigh = curr->neighbors;
            
            for(Node* n : neigh){
                if(mpp.find(n->val) == mpp.end()){
                    // q.push(n);
                    if(mpp.find(n->val) == mpp.end()){
                        mpp[n->val] = new Node(n->val);
                        q.push(n);
                    }
                }
                // else{
                    // nnode->neighbors.push_back(mpp[n->val]);
                // }
                mpp[curr->val]->neighbors.push_back(mpp[n->val]);
            }
        }
        return root;
    }
};