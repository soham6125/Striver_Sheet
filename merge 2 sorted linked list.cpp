class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL;
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        else
        {
            if((l1->val) >= (l2->val))
            {
                ans = l2;
                ans->next = mergeTwoLists(l1,l2->next);
            }
            else
            {
                ans = l1;
                ans->next = mergeTwoLists(l1->next,l2);
            }
        }
        return ans;
    }
};