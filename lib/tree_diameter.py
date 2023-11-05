from typing import List, Tuple
import sys

sys.setrecursionlimit(10**7)

INF = float("inf")


class Edge:
    def __init__(self, to: int, cost: int) -> None:
        self.to = to
        self.cost = cost


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
    p = dfs(G, 0, -1)
    q = dfs(G, p[1], -1)
    return q[0]


def main() -> None:
    N = int(input())
    G: List[List[Edge]] = [[] for _ in range(N)]

    for _ in range(N - 1):
        s, t, w = map(int, input().split())
        G[s].append(Edge(t, w))
        G[t].append(Edge(s, w))

    ans = tree_diameter(G)
    print(ans)


if __name__ == "__main__":
    main()
