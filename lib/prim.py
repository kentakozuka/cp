import heapq


# 隣接リストによるグラフ表現
Graph = list[list[tuple[int, int]]]


def prim(G: Graph) -> Graph:
    """最小全域木を求めるアルゴリズム

    Args:
        G (Graph): グラフ

    Returns:
        Graph: 最小全域木
    """
    ret = [[] for _ in range(len(G))]
    used = [False] * len(G)
    que = []
    heapq.heappush(que, (0, 0))
    while que:
        e = heapq.heappop(que)
        v = e[1]
        # 一回行ったところはスキップ
        if used[v]:
            continue
        used[v] = True
        ret[0].append((e[1], e[0]))
        # 次のノードをすべてキューにいれる
        for i in range(len(G[v])):
            que.append((G[v][i][1], G[v][i][0]))
            heapq.heapify(que)

    return ret


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
if __name__ == "__main__":
    V, E = map(int, input().split())
    G = [[] for _ in range(V)]

    for i in range(E):
        si, ti, wi = map(int, input().split())
        G[si].append((ti, wi))
        G[ti].append((si, wi))

    t = prim(G)

    # コストの総和
    ans = 0
    for i in range(len(t)):
        for j in range(len(t[i])):
            ans += t[i][j][1]
    print(ans)
