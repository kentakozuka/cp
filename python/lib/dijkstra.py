import heapq

INF = float("inf")


# グラフ
# スタート地点から各ノードへの最短距離を返す
# O((E+N)*logN)
# - 各辺のコストは非負の値(0以上)でなければならない
# - 負のコストが含まれてる場合はベルマン-フォード法などを使用する
def dijkstra(G, s):
    # 最短距離を初期化
    d = [INF] * len(G)
    d[s] = 0
    # 距離が小さい順に取り出せるようheapqを使用
    # (距離, 頂点番号)を要素とする優先度付きキューを用いる
    q = []
    heapq.heappush(q, (0, s))

    while len(q) > 0:
        # 更新した頂点の中で距離が最小の頂点 n
        p = heapq.heappop(q)
        n = p[1]
        if d[n] < p[0]:
            continue
        # 頂点nから出る辺eを走査
        for e in G[n]:
            # 移動した後のコストが小さいなら、頂点のコストを更新
            if d[n] + e[1] < d[e[0]]:
                d[e[0]] = d[n] + e[1]
                heapq.heappush(q, (d[e[0]], e[0]))
    return d


if __name__ == "__main__":
    N, E = map(int, input().split())
    r = int(input())

    G = [[] for _ in range(N)]

    # Create a graph.
    for i in range(E):
        s, t, c = map(int, input().split())
        e = (t, c)
        G[s].append(e)

    d = dijkstra(G, r)
    for i in range(N):
        print(d[i])
