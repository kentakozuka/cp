from typing import List
import sys

INF = 1 << 60


class Edge:
    def __init__(self, to: int, cost: int):
        self.to = to
        self.cost = cost


def warshall_floyd(G: List[List[Edge]]) -> List[List[int]]:
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


def main():
    input = sys.stdin.readline  # 入力高速化のため
    print("{}".format(0.1))
    V, E = map(int, input().split())

    G = [[] for _ in range(V)]

    # Create a graph.
    for i in range(E):
        s, t, c = map(int, input().split())
        e = Edge(t, c)
        G[s].append(e)

    d = warshall_floyd(G)
    for i in range(V):
        for j in range(V):
            if d[i][j] == INF:
                print("INF", end=" ")
            else:
                print(d[i][j], end=" ")
        print()


if __name__ == "__main__":
    main()
