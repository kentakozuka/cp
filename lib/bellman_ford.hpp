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
// スタート地点から各ノードへの最短(長)距離を返す
// pair<vector<最短距離>, 成功したか(負の閉路がないか)>
//
// - 辺の重みが負でも動く
// - すべての重みに-1をかけると最長距離を求められる
// - 非負ならDijkstra法を使った方が高速
// - 負の閉路があると正しい距離を求められないが、負の閉路があることを検出できる
pair<vector<ll>, bool> bellman_ford(Graph G, ll s) {
  vector<ll> d(G.size());
  fill(d.begin(), d.end(), LLONG_MAX);
  d[s] = 0;
  // ノード分ループ
  for (ll i = 0; i < G.size(); i++) {
    // エッジ分ループ
    for (ll j = 0; j < G.size(); j++) {
      for (ll k = 0; k < G[j].size(); k++) {
        Edge e = G[j][k];
        if (d[j] == LLONG_MAX) {
          continue;
        }
        // 移動した後のコストが小さいなら、頂点のコストを更新
        if (d[e.to] > d[j] + e.cost) {
          d[e.to] = d[j] + e.cost;
          // 頂点の数と同じ回数ループすると、負の閉路がある
          if (i == G.size() - 1) {
            return pair<vector<ll>, bool>(d, false);
          }
        }
      }
    }
  }
  return pair<vector<ll>, bool>(d, true);
}
