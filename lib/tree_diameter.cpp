#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

// pair<最遠点間距離, 最遠点> を求める
pair<ll, ll> dfs(Graph &G, ll idx, ll parent) {
  pair<ll, ll> ret(0, idx);
  for (auto &e : G[idx]) {
    if (e.to == parent) {
      continue;
    }
    auto cost = dfs(G, e.to, idx);
    cost.first += e.cost;
    if (ret.first < cost.first) {
      ret = cost;
    }
  }
  return ret;
}

// 重み付き木の直径を求める.
// (重みが与えられていない場合は, 全ての重みを1とする.)
// 頂点数をN, O(N).
ll tree_diameter(Graph &G) {
  auto p = dfs(G, 0, -1);
  auto q = dfs(G, p.second, -1);
  return q.first;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  ll N;
  cin >> N;
  Graph G(N);

  for (ll i = 0; i < N - 1; i++) {
    ll s, t, w;
    cin >> s >> t >> w;
    G[s].push_back(Edge{t, w});
    G[t].push_back(Edge{s, w});
  }

  ll ans = tree_diameter(G);
  cout << ans << endl;
  return 0;
}
