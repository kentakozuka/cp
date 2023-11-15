from .union_find import UnionFind


class Edge:
    def __init__(self, s: int, t: int, cost: int):
        self.s = s
        self.t = t
        self.cost = cost


def comp(e1: Edge, e2: Edge) -> bool:
    return e1.cost < e2.cost


def kruskal(v: int, es: list[Edge]) -> int:
    es.sort(key=comp)
    uf = UnionFind(v)
    res = 0
    for e in es:
        if not uf.same(e.s, e.t):
            uf.merge(e.s, e.t)
            res += e.cost
    return res
