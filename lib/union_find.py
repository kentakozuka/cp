class UnionFind:
    """
    Union find
    DSU(Disjoint Set Union)とも言われるらしい
    https://pyteyon.hatenablog.com/entry/2019/03/11/200000
    """

    def __init__(self, N):
        # parent[i]: iの親の番号
        self.parents = [i for i in range(N)]
        self.sizes = [1] * N

    def root(self, x):
        """
        データxが属する木の根を返す
        O(logN)
        """
        if self.parents[x] == x:
            return x
        self.parents[x] = self.root(self.parents[x])
        return self.parents[x]

    def merge(self, x, y):
        """
        xとyの木を併合
        """
        rx = self.root(x)
        ry = self.root(y)
        # xとyの根が同じ(=同じ木にある)時はそのまま
        if rx == ry:
            return
        # 小を大にくっつける
        if self.sizes[rx] < self.sizes[ry]:
            rx, ry = ry, rx
        self.parents[ry] = rx
        self.sizes[rx] += self.sizes[ry]

    def same(self, x, y):
        """
        2つのデータx, yが属する木が同じならtrueを返す
        """
        return self.root(x) == self.root(y)

    def size(self, x):
        """
        素集合のサイズ
        """
        return self.sizes[self.root(x)]
