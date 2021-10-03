#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

// 最小全域木を求めるアルゴリズム
// 計算量: O(ElogV)
// 既に到達した頂点集合からまだ到達していない頂点集合への辺のうち、コストが最小のものを選んでいく
Graph prim(Graph &G) {
  Graph ret(G.size());
  vector<bool> used(G.size(), false);
  auto c = [](Edge l, Edge r) { return l.cost > r.cost; };
  // コストが小さいものから取り出す
  // decltype(式): 式の型を返す
  priority_queue<Edge, vector<Edge>, decltype(c)> que(c);
  que.push(Edge{0, 0});
  while (!que.empty()) {
    auto e = que.top();
    que.pop();
    ll v = e.to;
    // 一回行ったところはスキップ
    if (used[v]) {
      continue;
    }
    used[v] = true;
    ret[0].push_back(e);
    // 次のノードをすべてキューにいれる
    for (ll i = 0; i < G[v].size(); i++) {
      que.push(G[v][i]);
    }
  }

  return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
int main() {
  int V, E;
  cin >> V >> E;

  Graph G(V);

  for (int i = 0; i < E; i++) {
    int si, ti, wi;
    cin >> si >> ti >> wi;
    G[si].push_back(Edge{ti, wi});
    G[ti].push_back(Edge{si, wi});
  }

  auto t = prim(G);

  // コストの総和
  ll ans = 0;
  for (ll i = 0; i < t.size(); i++) {
    for (ll j = 0; j < t[i].size(); j++) {
      ans += t[i][j].cost;
    }
  }
  cout << ans << endl;
  return 0;
}