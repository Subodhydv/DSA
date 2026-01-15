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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;

        while (temp != NULL) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* Kthnode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while (temp != NULL) {
            ListNode* lastnode = Kthnode(temp, k);

            if (lastnode == NULL) {
                if (prevnode) prevnode->next = temp;
                break;
            }

            ListNode* nextnode = lastnode->next;
            lastnode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevnode->next = newHead;
            }

            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};
