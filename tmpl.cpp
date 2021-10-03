#include <bits/stdc++.h>

// clang-format off
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
// const ll MOD = 998244353;

// 2次元vector: auto dp = make_vec<ll>(n + 1, 10);
template <typename T> vector<T> make_vec(size_t n) { return vector<T>(n); }
template <typename T, class... Args> auto make_vec(size_t n, Args... args) { return vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(args...)); }
// aをbで割る時の繰上げ,繰り下げ
ll myceil(ll a, ll b) { return (a + (b - 1)) / b; }
ll myfloor(ll a, ll b) { return a / b; }
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

void Solve();
signed main() {
  std::cin.tie(nullptr); // cin から読み込みをするたびに cout が flushさせるのを防ぐ.
  ios::sync_with_stdio(false);       //入力の高速化用のコード
  cout << setprecision(20) << fixed; //小数の桁数の出力指定
  Solve();
}
// clang-format on

// -----------------------
// Write your functions.
// -----------------------

void Solve() {
  // Write code here :)
}