#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 2147483647;

// セグメント木
// 計算量
// f()を変更することで異なるクエリに対応できる
// - 初期化: O(N*logN)
//   - O(N)でも実装できるらしい
// - update: O(logN)
// - query: O(logN)
struct SegmentTree {
  ll n; // 葉の数
  vector<ll> nodes;

  SegmentTree(vector<ll> v) {
    ll sz = v.size();
    n = 1;
    // セグメント木全体で必要なノード数は 2n-1
    while (n < sz)
      n *= 2;
    nodes.resize(2 * n - 1, INF);
    // 最下段に値を入れる
    for (ll i = 0; i < sz; i++)
      nodes[leef(i)] = v[i];
    // 親に値を入れるには、自分の子の2値を参照する
    for (ll i = last_parent(); i >= 0; i--)
      nodes[i] = f(nodes[left_child(i)], nodes[right_child(i)]);
  }

  ll leef(ll k) {
    return k + (n - 1);
  }
  ll last_parent() {
    return n - 2;
  }
  ll parent(ll child) {
    return (child - 1) / 2;
  }
  ll left_child(ll parent) {
    return parent * 2 + 1;
  }
  ll right_child(ll parent) {
    return parent * 2 + 2;
  }

  // i番目(0-index)の値をaに変更
  void update(ll i, ll a) {
    // 葉を更新
    i = leef(i);
    nodes[i] = a;
    // 登りながら更新
    while (i > 0) {
      i = parent(i);
      nodes[i] = f(nodes[left_child(i)], nodes[right_child(i)]);
    }
  }

  // [a, b) のXXXを求める
  //
  // [a, b) = クエリで与えられた区間 (実際に計算したい区間)
  // k      = 自分がいるノードのインデックス
  // [l, r) = nodes[k] がカバーしている区間
  // 最初は (a, b) で呼ぶ
  ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
    // 最初に呼び出されたときの[l, r)は [0, n)
    if (r < 0) r = n;

    // [a, b) と [l, r) が交差しなければ INF
    if (r <= a || b <= l) {
      return INF;
    }
    // [a, b) が [l, r) を完全に含んでいれば、この節点の値
    if (a <= l && r <= b) {
      return nodes[k];
    }
    // 最上段から下がっていく
    ll vl = query(a, b, left_child(k), l, (l + r) / 2);
    ll vr = query(a, b, right_child(k), (l + r) / 2, r);
    return f(vl, vr);
  }

  ll f(ll vl, ll vr) {
    return min(vl, vr); // 最小値を求める(Range Minumum Query)
    // return vl + vr; // 和を求める(Range Sum Query)
  }
};

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> coms, X, Y;
  for (ll i = 0; i < q; i++) {
    ll com, x, y;
    cin >> com >> x >> y;
    coms.push_back(com);
    X.push_back(x);
    Y.push_back(y);
  }

  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    v.push_back(INF);
  }
  SegmentTree st(v);

  for (ll i = 0; i < q; i++) {
    ll com = coms[i];
    ll x = X[i];
    ll y = Y[i];
    if (com == 0) {
      st.update(x, y);
    } else {
      cout << st.query(x, y + 1) << endl;
    }
  }
  return 0;
}