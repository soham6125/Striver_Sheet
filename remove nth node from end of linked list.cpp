class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        if(head == NULL) return NULL;
        ListNode *curr = head;
        while(curr)
        {
            size++;
            curr = curr->next;
        }
        if(size == n) return head->next;
        ListNode *node = head;
        int cnt = 1;
        while(cnt < size-n)
        {
            node = node->next;
            cnt++;
        }
        node->next = node->next->next;
        return head;
    }
};