#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
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

// BIT(Binary Index Tree)
// フェニック木(Fenwick Tree)とも呼ばれるらしい
// - sum: O(logN)
// - add: O(logN)
struct BIT {
  ll n;
  vector<ll> nodes;

  BIT(ll n) : n(n), nodes(n) {}

  void add(ll i, ll x) {
    assert(0 <= i && i < n);
    i++;
    while (i <= n) {
      nodes[i - 1] += x;
      i += i & -i;
    }
  }

  ll sum(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    return sum(r) - sum(l);
  }

  ll sum(int r) {
    ll s = 0;
    while (r > 0) {
      s += nodes[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
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

  // vector<ll> v;
  // for (ll i = 0; i < n; i++) {
  //   v.push_back(INF);
  // }
  BIT bit(n);

  for (ll i = 0; i < q; i++) {
    ll com = coms[i];
    ll x = X[i];
    ll y = Y[i];
    if (com == 0) {
      bit.add(--x, y);
    } else {
      cout << bit.sum(--x, --y) << endl;
    }
  }
  return 0;
}