from typing import List
import pytest
from lib.binary_search import BinarySearch


@pytest.mark.parametrize(
    "input, output",
    [
        (51, 3),
        (1, 0),
        (910, 9),
        (52, 6),
        (0, 0),
        (911, 10),
    ],
)
def test_is_prime(input, output):
    list: List[int] = [1, 14, 32, 51, 51, 51, 243, 419, 750, 910]
    bs = BinarySearch(list)
    actual = bs.binary_search(input)
    assert actual == output
