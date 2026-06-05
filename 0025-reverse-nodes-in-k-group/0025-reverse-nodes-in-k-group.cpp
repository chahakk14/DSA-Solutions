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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (head) {
            stack<ListNode*> st;
            ListNode* curr = head;

            int cnt = 0;
            while (curr && cnt < k) {
                st.push(curr);
                curr = curr->next;
                cnt++;
            }

            if (cnt < k) {
                tail->next = head;
                break;
            }

            while (!st.empty()) {
                tail->next = st.top();
                st.pop();
                tail = tail->next;
            }

            tail->next = curr;
            head = curr;
        }

        return dummy.next;
    }
};