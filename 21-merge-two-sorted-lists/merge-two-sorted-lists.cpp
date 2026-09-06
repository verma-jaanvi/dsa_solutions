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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->val <= curr2->val){
                ListNode* node = new ListNode(curr1->val);
                ans->next = node;
                ans = ans->next;
                curr1 = curr1->next;
            }else{
                ListNode* node = new ListNode(curr2->val);
                ans->next = node;
                ans = ans->next;
                curr2 = curr2->next;
            }
        }
        while(curr1 != nullptr){
                ListNode* node = new ListNode(curr1->val);
                ans->next = node;
                ans = ans->next;
                curr1 = curr1->next;
        }
        while(curr2 != nullptr){
                ListNode* node = new ListNode(curr2->val);
                ans->next = node;
                ans = ans->next;
                curr2 = curr2->next;
        }

        return dummy->next;
    }
};