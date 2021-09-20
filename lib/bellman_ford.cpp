#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

// ベルマン・フォード法
// O(EV)
// スタート地点から各ノードへの最短距離を返す
// pair<vector<最短距離>, 負の閉路があるか>
// - 辺の重みが負でも動きますが、非負ならDijkstra法を使った方が高速
// - 負の閉路があると正しい距離を求められないが、負の閉路があることを検出できる
pair<vector<ll>, bool> bellman_ford(Graph G, ll s) {
  vector<ll> d(G.size());
  fill(d.begin(), d.end(), LLONG_MAX);
  d[s] = 0;
  for (ll i = 0; i < G.size(); i++) {
    for (ll j = 0; j < G.size(); j++) {
      for (ll k = 0; k < G[j].size(); k++) {
        Edge e = G[j][k];
        if (d[e.to] > d[j] + e.cost) {
          d[e.to] = d[j] + e.cost;
          if (i == G.size() - 1) {
            return pair<vector<ll>, bool>(d, false);
          }
        }
      }
    }
  }
  return pair<vector<ll>, bool>(d, true);
}

int main() {
  cout << fixed << setprecision(10);

  ll V, E;
  cin >> V >> E;
  ll r;
  cin >> r;

  Graph G(V);

  // Create a graph.
  for (ll i = 0; i < E; i++) {
    ll s, t, c;
    cin >> s >> t >> c;
    Edge e = {t, c};
    G[s].push_back(e);
  }

  auto ret = bellman_ford(G, r);
  if (!ret.second) {
    cout << "negative loop" << endl;
    return 1;
  }
  for (ll i = 0; i < V; i++) {
    cout << ret.first[i] << endl;
  }
}