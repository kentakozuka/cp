#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// index が条件を満たすかどうか
// ここを変更する
bool isOK(ll index, ll key) {
  if (a[index] >= key)
    return true;
  else
    return false;
}

// めぐる式2分探索
// O(logN)
// 汎用的な二分探索のテンプレ
// https://qiita.com/drken/items/97e37dd6143e33a64c8c
ll binary_search(ll key) {
  //「index = 0」が条件を満たすこともあるので、初期値は -1
  ll ng = -1;
  //「index = a.size()-1」
  // が条件を満たさないこともあるので、初期値は a.size()
  ll ok = (ll)a.size();

  // ok と ng のどちらが大きいかわからないことを考慮
  // 大小関係は関係ない。条件を満たすかどうかで変える。
  // 基本は ng < mid < ok を考える
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOK(mid, key))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  // a[3] = 51
  // 「最小の index」なので 3)
  cout << binary_search(51) << endl;
  // a[0] = 1
  cout << binary_search(1) << endl;
  // a[9] = 910
  cout << binary_search(910) << endl;
  // 6
  cout << binary_search(52) << endl;
  // 0
  cout << binary_search(0) << endl;
  // 10 (場外)
  cout << binary_search(911) << endl;
}
