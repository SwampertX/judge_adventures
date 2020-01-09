# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def add(l1: ListNode, l2:ListNode, carry:int) -> ListNode:
            if not l1 and not l2:
                return ListNode(carry) if carry else None
            elif not l1:
                return add(l2, ListNode(carry), 0)
            elif not l2:
                return add(l1, ListNode(carry), 0)
            else:
                ans = l1.val + l2.val + carry
                ret = ListNode(ans%10)
                ret.next = add(l1.next, l2.next, ans//10)
                return ret
        return add(l1, l2, 0)
