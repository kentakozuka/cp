#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <time.h>
#include <tuple>
#include <vector>

using namespace std;

template <class T> using V = vector<T>;
using ll = long long;
using ull = unsigned long long;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)
#define SORT(a) sort((a).begin(), (a).end())
#define REV(a) reverse((a).begin(), (a).end())
#define ALL(a) (a).begin(), (a).end()

const long long INF = 1LL << 60;
const double PI = acos(-1);
const ll MOD = 1e9 + 7;

template <typename T> vector<T> make_vec(size_t n) { return vector<T>(n); }
template <typename T, class... Args> auto make_vec(size_t n, Args... args) {
  return vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(args...));
}

// aをbで割る時の繰上げ,繰り下げ
ll myceil(ll a, ll b) { return (a + (b - 1)) / b; }
ll myfloor(ll a, ll b) { return a / b; }

void Solve();

signed main() {
  // cin から読み込みをするたびに cout が flushさせるのを防ぐ.
  std::cin.tie(nullptr);
  //入力の高速化用のコード
  ios::sync_with_stdio(false);
  //小数の桁数の出力指定
  cout << setprecision(20) << fixed;
  Solve();
}

// -----------------------
// Write your functions.
// -----------------------

void Solve() {
  // Write code here :)
}