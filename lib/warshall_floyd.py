INF = 1 << 60


class Edge:
    def __init__(self, to: int, cost: int):
        self.to = to
        self.cost = cost


def warshall_floyd(G: list[list[Edge]]) -> list[list[int]]:
    """
    ワーシャルフロイド法
    O(V^3)
    全ての頂点間の最短距離を調べて経路の検出を行います
    """
    d = [[INF] * len(G) for _ in range(len(G))]
    for i in range(len(G)):
        d[i][i] = 0
        for e in G[i]:
            d[i][e.to] = e.cost

    for k in range(len(G)):
        for i in range(len(G)):
            for j in range(len(G)):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    return d
