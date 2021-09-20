using namespace std;

using ll = long long;

// 繰り返し二乗法
// ビルトインpowは浮動小数点で実装されているため、値が大きいと誤差が出る。
ll POW(ll a, ll n) {
  ll ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = ans * a;
    }
    a = a * a;
    n /= 2;
  }
  return ans;
}