#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL << 60;

using ll = long long;

struct Edge {
  ll to;
  ll cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;

// ダイクストラ
// スタート地点から各ノードへの最短距離を返す
// O(E*logN)
// - 各辺のコストは非負の値(0以上)でなければならない
// - 負のコストが含まれてる場合はベルマン-フォード法などを使用する
vector<ll> dijkstra(Graph &G, ll s) {
  // 最短距離を初期化
  vector<ll> d(G.size(), INF);
  // fill(d.begin(), d.end(), INF);
  d[s] = 0;
  // 距離が小さい順に取り出せるようgreater<P>を指定
  // first: 最短距離, second: 頂点番号
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(P(0, s));

  while (!q.empty()) {
    P p = q.top();
    q.pop();
    // 更新した頂点の中で距離が最小の頂点 n
    ll n = p.second;
    if (d[n] < p.first) {
      continue;
    }
    // 頂点nから出る辺eを走査
    for (auto e : G[n]) {
      // 移動した後のコストが小さいなら、頂点のコストを更新
      if (d[n] + e.cost < d[e.to]) {
        d[e.to] = d[n] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
  return d;
}

int main() {
  cout << fixed << setprecision(10);

  ll N, E;
  cin >> N >> E;
  ll r;
  cin >> r;

  Graph G(N);

  // Create a graph.
  for (ll i = 0; i < E; i++) {
    ll s, t, c;
    cin >> s >> t >> c;
    Edge e = {t, c};
    G[s].push_back(e);
  }

  auto d = dijkstra(G, r);
  for (int i = 0; i < N; i++) {
    cout << d[i] << endl;
  }
}