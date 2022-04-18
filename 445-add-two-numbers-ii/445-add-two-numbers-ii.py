# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        res = None

        l1_arr = []
        l2_arr = []

        currl1 = l1
        currl2 = l2
        carry = 0

        while currl1 is not None:
            l1_arr.append(currl1.val)
            currl1 = currl1.next
        while currl2 is not None:
            l2_arr.append(currl2.val)
            currl2 = currl2.next

        while l1_arr != [] or l2_arr != [] or carry != 0:
            if l1_arr != []:
                carry += l1_arr.pop()
            if l2_arr != []:
                carry += l2_arr.pop()

            carry, p = divmod(carry, 10)
            res = ListNode(p, res)
        return res