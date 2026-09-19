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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(auto it : lists){
            auto curr = it;
            while(curr != NULL){
                arr.push_back(curr->val);
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        sort(arr.begin(), arr.end());
        ListNode* curr = dummy;
        for(int i : arr){
            ListNode* node = new ListNode(i);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};