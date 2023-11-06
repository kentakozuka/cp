import pytest
from lib.gcd_lcm import gcd


@pytest.mark.parametrize(
    ["gcd_input", "gcd_expected"],
    [
        pytest.param((1, 2), 1),
        pytest.param((722, 171), 19),
    ],
)
def test_gcd(gcd_input, gcd_expected):
    actual = gcd(gcd_input[0], gcd_input[1])
    assert actual == gcd_expected
