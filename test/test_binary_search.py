import pytest
from lib.binary_search import BinarySearch


@pytest.mark.parametrize(
    [
        "input",
        "output",
    ],
    [
        pytest.param(51, 3),
        pytest.param(1, 0),
        pytest.param(910, 9),
        pytest.param(52, 6),
        pytest.param(0, 0),
        pytest.param(911, 10),
    ],
)
def test_is_prime(input, output):
    li = [1, 14, 32, 51, 51, 51, 243, 419, 750, 910]
    bs = BinarySearch(li)
    actual = bs.binary_search(input)
    assert actual == output
