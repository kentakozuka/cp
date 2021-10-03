#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < ll(n); i++)

const long long INF = 1LL << 60;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;

// ベルマン・フォード法
// O(EV)
// スタート地点から各ノードへの最短(長)距離を返す
// pair<vector<最短距離>, 成功したか(負の閉路がないか)>
//
// - 辺の重みが負でも動く
// - すべての重みに-1をかけると最長距離を求められる
// - 非負ならDijkstra法を使った方が高速
// - 負の閉路があると正しい距離を求められないが、負の閉路があることを検出できる
pair<vector<ll>, bool> bellman_ford(Graph G, ll s) {
  vector<ll> d(G.size());
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  // ノード分ループ
  REP(i, G.size()) {
    // for (ll i = 0; i < G.size(); i++) {
    // エッジ分ループ
    REP(j, G.size()) {
      // for (ll j = 0; j < G.size(); j++) {
      REP(k, G[j].size()) {
        // for (ll k = 0; k < G[j].size(); k++) {
        Edge e = G[j][k];
        if (d[j] == INF) {
          continue;
        }
        // 移動した後のコストが小さいなら、頂点のコストを更新
        if (d[e.to] > d[j] + e.cost) {
          d[e.to] = d[j] + e.cost;
          // 頂点の数と同じ回数ループすると、負の閉路がある
          if (i == ll(G.size() - 1)) {
            return pair<vector<ll>, bool>(d, false);
          }
        }
      }
    }
  }
  return pair<vector<ll>, bool>(d, true);
}
