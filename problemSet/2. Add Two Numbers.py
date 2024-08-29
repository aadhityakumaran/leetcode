# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        sol = ListNode()
        cursor = sol
        while l1 or l2 or carry:
            tot = 0

            if l1:
                tot += l1.val
                l1 = l1.next
            if l2:
                tot += l2.val
                l2 = l2.next
            tot += carry

            carry = 0
            if tot >= 10:
                tot %= 10
                carry = 1
                
            cursor.next = ListNode(tot)
            cursor = cursor.next
            
        cursor.next = None
        return sol.next
        