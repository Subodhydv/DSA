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
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;

        while (temp != NULL) {
            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        ListNode* newLastNode =
            findNthNode(head, len - k);

        ListNode* newHead = newLastNode->next;

        newLastNode->next = NULL;

        return newHead;
    }
};