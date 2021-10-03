#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long INF = 1LL << 60;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

// ワーシャルフロイド法
// グラフの全ての頂点の間の最短路を見つけるアルゴリズム
// O(V^3)
vector<vector<ll>> warshall_floyd(Graph G) {
  vector<vector<ll>> d(G.size(), vector<ll>(G.size(), INF));
  for (ll i = 0; i < G.size(); i++) {
    d[i][i] = 0;
    vector<Edge> edges = G[i];
    for (ll j = 0; j < edges.size(); j++) {
      Edge e = edges[j];
      d[i][e.to] = e.cost;
    }
  }
  for (ll k = 0; k < G.size(); k++) {
    for (ll i = 0; i < G.size(); i++) {
      for (ll j = 0; j < G.size(); j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}

int main() {
  cout << fixed << setprecision(10);

  ll V, E;
  cin >> V >> E;

  Graph G(V);

  // Create a graph.
  for (ll i = 0; i < E; i++) {
    ll s, t, c;
    cin >> s >> t >> c;
    Edge e = {t, c};
    G[s].push_back(e);
  }

  vector<vector<ll>> d = warshall_floyd(G);
  for (ll i = 0; i < V; i++) {
    for (ll j = 0; j < V; j++) {
      cout << d[i][j];
      cout << " ";
    }
    cout << endl;
  }
}