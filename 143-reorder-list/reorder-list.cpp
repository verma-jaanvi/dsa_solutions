/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while(curr != NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        vector<int> ans;
        int i = 0, j = arr.size()-1;
        while(i <= j){
            if(i == j){
                ans.push_back(arr[i]);
            }else{
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            i++;
            j--;
        }

        curr = head;
        i = 0;
        while(curr != nullptr){
            curr->val = ans[i++];
            curr = curr->next;
        }
        // return head;
    }
};