from typing import List, Tuple

INF = 1 << 60


class Edge:
    def __init__(self, to: int, cost: int):
        self.to = to
        self.cost = cost


def bellman_ford(G: List[List[Edge]], s: int) -> Tuple[List[int], bool]:
    """
    ベルマン・フォード法
    O(EV)
    スタート地点から各ノードへの最短(長)距離を返す
    pair<vector<最短距離>, 成功したか(負の閉路がないか)>

    - 辺の重みが負でも動く
    - すべての重みに-1をかけると最長距離を求められる
    - 非負ならDijkstra法を使った方が高速
    - 負の閉路があると正しい距離を求められないが、負の閉路があることを検出できる
    """
    n = len(G)
    d = [INF] * n
    d[s] = 0

    for i in range(n):
        for j in range(n):
            for k in range(len(G[j])):
                e = G[j][k]
                if d[j] == INF:
                    continue
                if d[e.to] > d[j] + e.cost:
                    d[e.to] = d[j] + e.cost
                    if i == n - 1:
                        return d, False
    return d, True
