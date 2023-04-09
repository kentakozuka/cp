# Union find
# DSU(Disjoint Set Union)とも言われるらしい
# https://pyteyon.hatenablog.com/entry/2019/03/11/200000


class UnionFind:
    def __init__(self, N):
        # par[i]: iの親の番号
        # 例) par[3] = 2 (3の親が2)
        self.par = [i for i in range(N)]
        self.sizes = [1] * N

    # データxが属する木の根を返す
    # O(logN)
    def root(self, x):
        if self.par[x] == x:
            return x
        self.par[x] = self.root(self.par[x])
        return self.par[x]

    # xとyの木を併合
    def merge(self, x, y):
        rx = self.root(x)
        ry = self.root(y)
        # xとyの根が同じ(=同じ木にある)時はそのまま
        if rx == ry:
            return
        # 小を大にくっつける
        if self.sizes[rx] < self.sizes[ry]:
            rx, ry = ry, rx
        self.par[ry] = rx
        self.sizes[rx] += self.sizes[ry]

    # 2つのデータx, yが属する木が同じならtrueを返す
    def same(self, x, y):
        return self.root(x) == self.root(y)

    # 素集合のサイズ
    def size(self, x):
        return self.sizes[self.root(x)]
