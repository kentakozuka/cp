from typing import List
import pytest
from lib.tree_diameter import Edge, tree_diameter

g: List[List[Edge]] = [
    [Edge(1, 1), Edge(2, 1)],
    [Edge(0, 1), Edge(3, 1)],
    [Edge(0, 1), Edge(6, 1)],
    [Edge(1, 1), Edge(4, 1), Edge(5, 1)],
    [Edge(3, 1)],
    [Edge(3, 1)],
    [Edge(2, 1), Edge(7, 1)],
    [Edge(6, 1), Edge(8, 1), Edge(9, 1)],
    [Edge(7, 1)],
    [Edge(7, 1)],
]


@pytest.mark.parametrize(
    ["input", "expected"],
    [
        pytest.param(g, 7),
    ],
)
def test_tree_diameter(input, expected):
    actual = tree_diameter(input)
    assert actual == expected
