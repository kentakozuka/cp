#ifndef POW_HPP
#define POW_HPP 1

#include <iostream>

using namespace std;

using ll = long long;

// 繰り返し二乗法
// 時間計算量: O(logN)
// 空間計算量: O(1)
// 指数を2の累乗の積に分解し、計算を効率化する
// ビルトインpowは浮動小数点で実装されているため、誤差が出る。
// - ダブリングの一種
// - 実際は実装はnを2進数でみて、下からi桁目が1ならx^(2^i)をかける
ll POW(ll a, ll n) {
  ll ret = 1;
  while (n > 0) {
    // n の最下位bitが 1 ならば a^(2^i) をかける
    if (n & 1) {
      ret *= a;
    }
    a *= a;
    // n を左シフト
    n >>= 1;
  }
  return ret;
}

#endif // POW_HPP