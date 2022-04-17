# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        def reverse(head):
            prev, curr = None, head

            while curr:
                next_node = curr.next
                curr.next = prev
                prev, curr = curr, next_node
            return prev

        slow, fast = head, head

        while fast:
            slow = slow.next
            fast = fast.next.next

        first = head
        second = reverse(slow)
        max_res = 0

        while second:
            sum_of_fast_and_slow = first.val + second.val
            max_res = max(sum_of_fast_and_slow, max_res)
            first, second = first.next, second.next
        return max_res