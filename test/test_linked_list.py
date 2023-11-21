import pytest
from lib.linked_list import ListNode, reverse_list


@pytest.mark.parametrize(
    ["reverse_list_input", "reverse_list_expected"],
    [
        pytest.param([1, 2, 3, 4, 5], [5, 4, 3, 2, 1]),
    ],
)
def test_gcd(reverse_list_input, reverse_list_expected):
    head = ListNode(reverse_list_input[0], None)
    prev = head
    for i in range(1, len(reverse_list_input)):
        prev.next = ListNode(reverse_list_input[i], None)
        prev = prev.next
    actual = reverse_list(head)
    actual_list = []
    while actual:
        actual_list.append(actual.val)
        actual = actual.next

    assert actual_list == reverse_list_expected
