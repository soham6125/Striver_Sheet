class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *slowptr = head;
        ListNode *fastptr = head;
        while(fastptr and fastptr->next and slowptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
    }
};