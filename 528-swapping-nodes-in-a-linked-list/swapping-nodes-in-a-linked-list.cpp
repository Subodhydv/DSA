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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *second = head, *curr;
        
        for(int i = 1; i < k; i++) {
            first = first->next;
        }
        
        curr = first;
        
        while(curr->next != NULL) {
            curr = curr->next;
            second = second->next;
        }
        
        int t = first->val;
        first->val = second->val;
        second->val = t;
        
        return head;
    }
};