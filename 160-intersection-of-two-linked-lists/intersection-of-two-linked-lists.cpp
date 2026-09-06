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
        unordered_map<ListNode*, int> seen;
        ListNode* curr1 = headA; ListNode* curr2 = headB;
        while(curr1!= nullptr){
            // if(seen[curr1]) return curr1;
            seen[curr1] = 1;
            curr1 = curr1->next;
            
        }

        while(curr2 != nullptr){
            if(seen[curr2]) return curr2;
            seen[curr2]= 1;
            curr2 = curr2->next;
        }

        return nullptr;
    }
};