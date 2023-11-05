import pytest
from lib.combination import nCr


@pytest.mark.parametrize(
    "ncr_input, ncr_expected",
    [
        ([10, 0], 1),
        ([10, 1], 10),
        ([10, 3], 120),
        ([10, 9], 10),
        ([10, 10], 1),
    ],
)
def test_ncr(ncr_input, ncr_expected):
    actual = nCr(ncr_input[0], ncr_input[1])
    assert actual == ncr_expected
