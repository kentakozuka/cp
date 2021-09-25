#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
  ll n = 3;

  // bit全探索
  // N個のものから、いくつか選ぶ方法を全列挙して調べ上げる手法
  // O(N*2^N)
  // (1<<N)は2^Nの意味
  for (ll bit = 0; bit < (1 << n); ++bit) {
    vector<ll> S;
    for (ll i = 0; i < n; i++) {
      // 列挙に i が含まれるか
      // (1<<i): i桁目のみが1で他は0であるようなビット列である
      // &は論理積:
      if (bit & (1 << i)) {
        S.push_back(i);
      }
    }
    cout << bit << ": {";
    for (ll i = 0; i < (ll)S.size(); ++i) {
      cout << S[i] << " ";
    }
    cout << "}" << endl;
  }
}