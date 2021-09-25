#include <iostream>

using namespace std;

using ll = long long;

// 繰り返し二乗法
// 時間計算量: O(logN)
// 空間計算量: O(1)
// 指数を2の累乗の積に分解し、計算を効率化する
// ビルトインpowは浮動小数点で実装されているため、誤差が出る。
// 実際は実装はnを2進数でみて、下からi桁目が1ならx^(2^i)をかける
ll POW(ll a, ll n) {
  ll ret = 1;
  while (n > 0) {
    // n の最下位bitが 1 ならば x^(2^i) をかける
    if (n & 1) ret *= a;
    a *= a;
    // n を1bit 左にずらす
    n >>= 1;
  }
  return ret;
}

int main() {
  cout << POW(3, 21) << endl;
}