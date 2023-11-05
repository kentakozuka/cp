import pytest
from lib.prime_number import divisors, is_prime


@pytest.mark.parametrize(
    ["is_prime_input", "is_prime_expected"],
    [
        pytest.param(1, False),
        pytest.param(2, True),
        pytest.param(3, True),
        pytest.param(4, False),
        pytest.param(1000000007, True),
    ],
)
def test_is_prime(is_prime_input, is_prime_expected):
    actual = is_prime(is_prime_input)
    assert actual == is_prime_expected


@pytest.mark.parametrize(
    ["divisors_input", "divisors_expected"],
    [
        pytest.param(2, [1, 2]),
        pytest.param(3, [1, 3]),
        pytest.param(4, [1, 4, 2]),
        pytest.param(6, [1, 6, 2, 3]),
        pytest.param(12, [1, 12, 2, 6, 3, 4]),
        pytest.param(1000000007, [1, 1000000007]),
    ],
)
def test_divisors(divisors_input, divisors_expected):
    actual = divisors(divisors_input)
    assert actual == divisors_expected
