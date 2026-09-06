class Node{
public:
    char data;
    vector<Node*> children;
    bool isEnd;

    Node(char ch){
        data = ch;
        isEnd = false;
        for(int i = 0; i<26; ++i){
            children.push_back(NULL);
        }
    }

    void insert(Node* root, string s){
        Node* curr = root;
        for(char ch : s){
            int idx = ch - 'a';
            if(!curr->children[idx]){
                curr->children[idx] = new Node(ch);
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
};


class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        Node* root = new Node('0');
        for(string s : strs){
            root->insert(root, s);
        }
        string ans = "";
        while(!root->isEnd){
            int cnt = 0;
            Node* next = NULL;
            for(int i = 0; i<26; ++i){
                if(root->children[i]){   
                    cnt++;
                    next = root->children[i];
                }
                if(cnt > 1) break;
            }
            if(cnt == 1){   
                root = next; 
                ans +=root->data;
            }
            else break;
            
        }
        return ans;
    }
};