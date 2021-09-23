#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;

struct Edge {
  ll to;
};
using Graph = vector<vector<Edge>>;

// BFSトポロジカルソート
// O(E+V)
// 「ret.size() == 頂点の数」なら閉路なし
vector<ll> topo_sort(Graph &G) {
  vector<ll> ret;

  // ind[i]: 頂点iに入る辺の数(次数 indegree)
  vector<ll> ind(G.size());
  // 次数を数えておく
  for (ll i = 0; i < G.size(); i++) {
    for (auto e : G[i]) {
      ind[e.to]++;
    }
  }

  // 次数が0の点をキューに入れる
  queue<ll> que;
  for (ll i = 0; i < G.size(); i++) {
    if (ind[i] == 0) {
      que.push(i);
    }
  }

  // 幅優先探索
  while (!que.empty()) {
    ll cur = que.front();
    que.pop();
    ret.push_back(cur);
    for (auto e : G[cur]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        que.push(e.to);
      }
    }
  }
  return ret;
}

// トポロジカルソート https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
// 閉路検出 https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_A
int main(void) {
  ll V, E;
  cin >> V >> E;

  // 隣接リストにより表現されるグラフ
  Graph G(V);
  for (ll i = 0; i < E; i++) {
    ll s, t;
    cin >> s >> t;
    Edge e = {t};
    G[s].push_back(e);
  }

  vector<ll> ans = topo_sort(G);

  // 閉路検出
  // if (ans.size() == G.size()) {
  //   cout << 0 << endl; // なし
  //   return 0;
  // } else {
  //   cout << 1 << endl; // あり
  //   return 0;
  // }

  // トポロジカルソートを出力
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}