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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* newhead = new ListNode(INT_MIN);
        ListNode* tail = newhead;
        int sum = 0, carry = 0;
        while(temp1 or temp2)
        {  
            if(temp1 && temp2){
                sum = (temp1 -> val + temp2 -> val) + carry;
                temp1 = temp1->next;
                temp2 = temp2->next;                
            }
            else if(temp1){
                sum = temp1->val+ carry;
                temp1 = temp1->next;
            }
            else{
                sum = temp2->val + carry;
                temp2 = temp2->next; 
            }
            carry = sum / 10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail = tail->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }
        return newhead->next;
    }
};