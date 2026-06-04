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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL ||head->next == NULL|| left == right){
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *before = &dummy;

        for(int i = 1; i < left; i++){
            before = before->next;
        }

        ListNode *prev=NULL;
        ListNode *curr=  before->next;
        ListNode *forward=NULL;
        ListNode *start = curr;

        for(int i = 0; i < right - left + 1; i++){
            forward=curr->next;
            curr->next= prev;
            prev=curr;
            curr=forward;
        }

        before->next = prev;
        start->next = curr;
        return dummy.next;
    }
};