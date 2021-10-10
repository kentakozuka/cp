#ifndef COMBINATION_HPP
#define COMBINATION_HPP 1

#include <vector>

using namespace std;
typedef long long ll;

// ref. https://www.kaoken.cg0.xyz/math_combination/

// 組み合わせ (combination) を求める
ll nCr(ll n, ll r) {
  if (r > n) return 0;
  if (r == 0 || n == r) return 1;
  if (r * 2 > n) r = n - r;

  ll res = n;
  for (ll i = 2; i <= r; i++) {
    res *= (n - i + 1);
    res /= i;
  }
  return res;
}

// 二項係数ライブラリ
struct BiCoef {
  ll mod, max;
  vector<ll> fac, finv, inv;

  // テーブルを作る前処理
  // O(n)
  BiCoef(ll mod, ll max) : mod(mod), max(max) {
    fac = vector<ll>(max);
    finv = vector<ll>(max);
    inv = vector<ll>(max);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max; i++) {
      fac[i] = fac[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }

  // 二項係数計算
  // O(1)
  ll com(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
  }
};

// 重複組み合わせを求める
// r個のものをn種類にわける
//
// ref. https://mathtrain.jp/tyohukuc
ll nHr(ll n, ll r) {
  return nCr(n + r - 1, r);
}

#endif // COMBINATION_HPP