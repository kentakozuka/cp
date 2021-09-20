#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

// ref. https://www.kaoken.cg0.xyz/math_combination/

// 組み合わせ (combination) を求める
ll nCr(ll n, ll r) {
  if (r > n)
    return 0;
  if (r == 0 || n == r)
    return 1;
  if (r * 2 > n)
    r = n - r;

  ll res = n;
  for (ll i = 2; i <= r; i++) {
    res *= (n - i + 1);
    res /= i;
  }
  return res;
}

// 重複組み合わせを求める
// r個のものをn種類にわける
//
// ref. https://mathtrain.jp/tyohukuc
ll nHr(ll n, ll r) { return nCr(n + r - 1, r); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cout << nCr(10, 0) << endl;
  cout << nCr(10, 1) << endl;
  cout << nCr(10, 3) << endl;
  cout << nCr(10, 9) << endl;
  cout << nCr(10, 10) << endl;
  cout << nHr(7, 3) << endl;
  return 0;
}
