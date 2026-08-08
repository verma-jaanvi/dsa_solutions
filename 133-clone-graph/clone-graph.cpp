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
        queue<Node*> q;
        Node* root = new Node(node->val);
        
        mpp[node->val] = root;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            
            vector<Node*> neigh = curr->neighbors;
            
            for(Node* n : neigh){
                if(mpp.find(n->val) == mpp.end()){
                    // if(mpp.find(n->val) == mpp.end()){
                        mpp[n->val] = new Node(n->val);
                        q.push(n);
                    // }
                }
                
                mpp[curr->val]->neighbors.push_back(mpp[n->val]);
            }
        }
        return root;
    }
};