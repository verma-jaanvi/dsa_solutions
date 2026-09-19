/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* st1 = headA;
        unordered_map<ListNode*, bool> seen;
        while(st1 != NULL){
            seen[st1] = true;
            st1 = st1->next;
        }

        ListNode* st2 = headB;
        while(st2 != NULL){
            if(seen[st2])   return st2;
            st2 = st2->next;
        }
        return NULL;
    }
};