# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry=0;
        res=n=ListNode(0);
        while l1 or l2 or carry:
            if l1:
                carry +=l1.val
                l1=l1.next;
            if l2:
                carry+=l2.val;
                l2=l2.next;
            carry,val=divmod(carry,10)
            n.next=n=ListNode(val);
            
        return res.next;