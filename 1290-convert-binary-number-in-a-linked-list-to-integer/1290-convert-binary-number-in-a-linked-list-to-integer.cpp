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
    int getDecimalValue(ListNode* head) {
        ListNode* temp= head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        temp=head;
        int result = 0 ;
        while(temp!=NULL){
            result= result + temp->val * pow(2,count-1);
            count--;
            temp=temp->next;
        }
        return result;
    }
};