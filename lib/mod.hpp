#ifndef MOD_HPP
#define MOD_HPP 1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 負の数にも対応した % 演算
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
ll mod(ll val, ll mod) {
  ll res = val % mod;
  if (res < 0) res += mod;
  return res;
}

// x^n
// 繰り返し二乗法 (O(logN))
ll modpow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll mod) {
  return modpow(a, mod - 2, mod);
}

// a / b
ll moddiv(ll a, ll b, ll mod) {
  a %= mod;
  return (a * modinv(b, mod)) % mod;
}

// 二項係数
ll modcombi(int n, int k, int mod) {
  ll ans = 1;
  for (ll i = n; i > n - k; i--) {
    ans *= i;
    ans %= mod;
  }
  for (ll i = 1; i <= k; i++) {
    ans *= modinv(i, mod);
    ans %= mod;
  }

  return ans;
}

#endif // MOD_HPP