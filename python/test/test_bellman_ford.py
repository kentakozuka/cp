from pathlib import Path
import sys

import pytest

sys.path.append(str(Path(__file__).parent.parent))
sys.path.append(str(Path(__file__).parent.parent / "src"))

from lib.bellman_ford import bellman_ford, Edge


@pytest.mark.parametrize(
    "input, expected",
    [
        ([[Edge(1, 2), Edge(2, 4)], [Edge(2, 1), Edge(3, 5)], [Edge(3, 2)], []], [0, 2, 3, 5]),
    ],
)
def test_bellman_ford(input, expected):
    actual, success = bellman_ford(input, 0)
    assert actual == expected
