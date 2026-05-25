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
        int size = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }

        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        curr = head;
        for (int i = 1; i < size - n; i++) {
            curr = curr->next;
        }

        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return head;
    }
};