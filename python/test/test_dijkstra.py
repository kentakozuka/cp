import pytest
from lib.combination import nCr


@pytest.mark.parametrize(
    "dijkstra_input, dijkstra_expected",
    [
        ([10, 0], 1),
    ],
)
def test_dijkstra(dijkstra_input, dijkstra_expected):
    actual = nCr(dijkstra_input[0], dijkstra_input[1])
    assert actual == dijkstra_expected
