# https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao

from typing import List, Tuple


n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)

# n個の頂点の色を初期化。0:未着色、1:黒、-1:白
colors = [0 for i in range(n)]


# 2部グラフならTrue, そうでなければFalse
def is_bipartite():
    for i in range(n):
        if colors[i] != 0:
            continue
        stack: List[Tuple[int, int]] = [(i, 1)]  # (頂点、色)のタプルをスタックする。最初は(頂点0, 黒(1))
        while stack:
            # スタックから最後に追加された(頂点, 色)をpop
            v, color = stack.pop()
            # 今いる点を着色
            colors[v] = color
            # 今の頂点から行けるところをチェック
            for to in g[v]:
                # 同じ色が隣接してしまったらFalse
                if colors[to] == color:
                    return False
                # 未着色の頂点があったら反転した色と共にスタックに積む
                if colors[to] == 0:
                    stack.append((to, -color))
    # 調べ終わったら矛盾がないのでTrue
    return True


print("Yes" if is_bipartite() else "No")
