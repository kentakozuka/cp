#ifndef KRUSCAL_HPP
#define KRUSCAL_HPP 1

#include "lib/union_find.hpp"
#include <vector>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)

struct Edge {
  int s, t, cost;
};

bool comp(const Edge &e1, const Edge &e2) {
  return e1.cost < e2.cost;
}

// 最小全域木を求めるアルゴリズム
// 計算量: O(ElogV)
//
// 1. 辺集合をコストの小さい順にソートする
// 2. 以下を繰り返す
//   - コストが最小の辺を取り出す
//   - 取り出した辺を加えても閉路ができない場合は加える
int kruskal(int v, vector<Edge> es) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(v);
  int res = 0;
  REP(i, es.size()) {
    Edge e = es[i];
    if (!uf.same(e.s, e.t)) {
      uf.merge(e.s, e.t);
      res += e.cost;
    }
  }
  return res;
}

#endif // KRUSCAL_HPP