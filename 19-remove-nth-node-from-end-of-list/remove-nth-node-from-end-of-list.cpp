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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while(curr != nullptr){
            curr = curr->next;
            len++;
        } 
        if(len == n){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;

        }
        n = len-n;
        curr = head;
        for(int i = 1; i<n; ++i){
            curr = curr->next;
        }
        if(curr->next == nullptr)  return nullptr;
        ListNode* node = curr->next;
        curr->next =  curr->next->next; 
        
        delete node;
        return head;
    }
};