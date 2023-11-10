from typing import List, Tuple


class Edge:
    def __init__(self, to: int, cost: int = 1) -> None:
        self.to = to
        self.cost = cost


def dfs(G: List[List[Edge]], idx: int, parent: int) -> Tuple[int, int]:
    """
    再帰DFS
    idxのノードから最も遠い（コストが高い）ノードとそのコストを返す
    """
    ret = (idx, 0)
    for e in G[idx]:
        if e.to == parent:
            continue
        farthest, cost = dfs(G, e.to, idx)
        cost += e.cost
        if ret[1] < cost:
            ret = (farthest, cost)
    return ret


def tree_diameter(G: List[List[Edge]]) -> int:
    """
    木の直径
    O(N)
    """
    p = dfs(G, 0, -1)
    q = dfs(G, p[0], -1)
    return q[1]
