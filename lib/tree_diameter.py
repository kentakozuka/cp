from typing import List, Tuple


class Edge:
    def __init__(self, to: int, cost: int) -> None:
        self.to = to
        self.cost = cost


# 再帰DFS
def dfs(G: List[List[Edge]], idx: int, parent: int) -> Tuple[int, int]:
    ret = (0, idx)
    for e in G[idx]:
        if e.to == parent:
            continue
        cost, far = dfs(G, e.to, idx)
        cost += e.cost
        if ret[0] < cost:
            ret = (cost, far)
    return ret


def tree_diameter(G: List[List[Edge]]) -> int:
    """
    木の直径
    O(N)
    """
    p = dfs(G, 0, -1)
    q = dfs(G, p[1], -1)
    return q[0]
