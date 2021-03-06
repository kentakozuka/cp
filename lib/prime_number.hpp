#ifndef PRIME_NUMBER_HPP
#define PRIME_NUMBER_HPP 1

#include <vector>

using namespace std;
typedef long long ll;

// 素数判定
// O(sqrt N)
// verify: https://atcoder.jp/contests/arc017/tasks/arc017_1
bool is_prime(int x) {
  // 2  から sqrt n まで繰り返す
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

// 約数列挙(未ソート)
// O(sqrt N)
vector<int> divisors(int x) {
  // 2  から sqrt n まで繰り返す
  vector<int> ret;
  for (int i = i; i * i <= x; i++) {
    if (x % i == 0) {
      ret.push_back(i);
      ret.push_back(x / i);
    }
  }
  return ret;
}

// 素因数分解
// O(sqrt N)
// 返却値: vector<pair<約数, 指数>>
// verify:
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
vector<pair<ll, ll>> prime_factorize(ll N) {
  vector<pair<ll, ll>> res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    // 指数
    ll ex = 0;
    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    // その結果を push
    res.push_back({a, ex});
  }
  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

#endif // PRIME_NUMBER_HPP