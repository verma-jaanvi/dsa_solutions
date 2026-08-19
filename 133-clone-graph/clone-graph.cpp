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
        unordered_map<int, Node*> mpp;
        queue<Node*> q;
        Node* root = new Node(node->val);
        mpp[node->val] = root;
        q.push(node);
        while(!q.empty()){
            Node* og = q.front(); q.pop();
            vector<Node*> neigh = og->neighbors;
            for(auto &ni : neigh){
                if(mpp.find(ni->val) == mpp.end()){
                    Node* nnode = new Node(ni->val);
                    mpp[ni->val] = nnode;
                    q.push(ni);
                }
                mpp[og->val]->neighbors.push_back(mpp[ni->val]);
            }
        }
        return root;
    }
};