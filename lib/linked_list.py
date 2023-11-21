class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverse_list(head: ListNode):
    prev = None
    curr = head
    while curr:
        next_node = curr.next  # first, make sure we don't lose the next node
        curr.next = prev  # reverse the direction of the pointer
        prev = curr  # set the current node to prev for the next node
        curr = next_node  # move on
    return prev


def get_middle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow.val


def hasCycle(self, head: ListNode) -> bool:
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
