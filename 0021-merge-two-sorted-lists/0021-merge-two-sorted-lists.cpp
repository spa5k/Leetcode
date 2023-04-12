class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *pre = new ListNode(-1);
        ListNode *prev = pre;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                prev->next = list1;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        if (list1 == NULL && list2 != NULL)
        {
            prev->next = list2;
        }
        else if (list1 != NULL && list2 == NULL)
        {
            prev->next = list1;
        }
        return pre->next;
    }
};