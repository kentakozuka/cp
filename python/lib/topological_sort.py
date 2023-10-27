from typing import List


class Edge:
    def __init__(self, to: int):
        self.to = to


class Graph:
    def __init__(self, n: int):
        self.adj = [[] for _ in range(n)]

    def add_edge(self, u: int, v: int):
        self.adj[u].append(Edge(v))


def topo_sort(G: Graph) -> List[int]:
    """
    BFSトポロジカルソート
    O(E+V)
    「len(ret) == 頂点の数」なら閉路なし
    DAG(閉路のない有向グラフ)の辺が左から右に向くように，頂点を左から右に一列に並べる方法．
    有向グラフをトポロジカルソートできなければ閉路がある
    """
    n = len(G.adj)
    ret = []

    # ind[i]: 頂点iに入る辺の数(次数 indegree)
    ind = [0] * n
    # 次数を数えておく
    for u in range(n):
        for e in G.adj[u]:
            ind[e.to] += 1

    # 次数が0の点をキューに入れる
    que = []
    for u in range(n):
        if ind[u] == 0:
            que.append(u)

    # 幅優先探索
    while que:
        cur = que.pop(0)
        ret.append(cur)
        for e in G.adj[cur]:
            ind[e.to] -= 1
            if ind[e.to] == 0:
                que.append(e.to)

    return ret


# トポロジカルソート https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
# 閉路検出 https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_A
def main():
    V, E = map(int, input().split())

    # 隣接リストにより表現されるグラフ
    G = Graph(V)
    for i in range(E):
        s, t = map(int, input().split())
        G.add_edge(s, t)

    ans = topo_sort(G)

    # 閉路検出
    # if len(ans) == V:
    #     print(0) # なし
    # else:
    #     print(1) # あり

    # トポロジカルソートを出力
    for u in ans:
        print(u)


if __name__ == "__main__":
    main()
