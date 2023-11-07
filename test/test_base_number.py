from pathlib import Path
import sys

import pytest

sys.path.append(str(Path(__file__).parent.parent))
sys.path.append(str(Path(__file__).parent.parent / "src"))

from lib.base_number import basex_to_decimal, decimal_to_basex


@pytest.mark.parametrize(
    ["basex_to_decimal_input", "basex_to_decimal_expected"],
    [
        pytest.param(("1000", 2), 8),
    ],
)
def test_basex_to_decimal(basex_to_decimal_input, basex_to_decimal_expected):
    actual = basex_to_decimal(basex_to_decimal_input[0], base=basex_to_decimal_input[1])
    assert actual == basex_to_decimal_expected


@pytest.mark.parametrize(
    ["decimal_to_basex_input", "decimal_to_basex_expected"],
    [
        pytest.param((8, 2), 1000),
    ],
)
def test_decimal_to_basex(decimal_to_basex_input, decimal_to_basex_expected):
    actual = decimal_to_basex(decimal_to_basex_input[0], base=decimal_to_basex_input[1])
    assert actual == decimal_to_basex_expected
