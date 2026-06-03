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
    ListNode* partition(ListNode* head, int x) {
          ListNode less(0);
         ListNode gtr(0);

         ListNode* ptr1 = &less;
         ListNode* ptr2 = &gtr;

         while(head){

            if(head->val < x){
                ptr1->next = head;   
                ptr1 = head;
            }
            else{
                ptr2->next = head;
                ptr2 = head;
            }

            head = head->next;         
         }

         ptr2->next = NULL;
         ptr1->next = gtr.next;     

         return less.next;
    }
};