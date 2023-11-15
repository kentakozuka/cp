from lib.warshall_floyd import Edge, warshall_floyd


def test_warshall_floyd():
    g: list[list[Edge]] = [
        [Edge(1, 1), Edge(2, 2)],
        [Edge(0, 1), Edge(3, 4)],
        [Edge(0, 2), Edge(5, 6), Edge(4, 7)],
        [Edge(1, 4), Edge(4, 8), Edge(5, 9)],
        [Edge(3, 8), Edge(2, 7)],
        [Edge(3, 9), Edge(2, 6)],
    ]
    actual = warshall_floyd(g)
    assert actual[0] == [0, 1, 2, 5, 9, 8]
    assert actual[1] == [1, 0, 3, 4, 10, 9]
    assert actual[2] == [2, 3, 0, 7, 7, 6]
    assert actual[3] == [5, 4, 7, 0, 8, 9]
    assert actual[4] == [9, 10, 7, 8, 0, 13]
    assert actual[5] == [8, 9, 6, 9, 13, 0]
