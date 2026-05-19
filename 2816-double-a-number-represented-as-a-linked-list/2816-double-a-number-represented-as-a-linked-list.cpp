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
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr= head;
        ListNode* prev= NULL;
        ListNode* next= NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head= reverse(head);
        ListNode* temp= head;
        int carry= 0;

        while(temp!=NULL){
            int ans= temp->val*2 + carry;
            int digit= ans%10;
            carry=ans/10;
            temp->val=digit;

            if (temp->next == NULL && carry != 0) {
                temp->next = new ListNode(carry);
                break;
            }

            temp=temp->next;
        }
        head= reverse(head);
        return head;
    }
};