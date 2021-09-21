#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

// Union find
// DSU(Disjoint Set Union)とも言われるらしい
// https://pyteyon.hatenablog.com/entry/2019/03/11/200000
struct UnionFind {
  // par[i]:iの親の番号
  // 例) par[3] = 2 (3の親が2)
  vector<int> par;
  vector<int> sizes;

  //最初は全てが根であるとして初期化
  UnionFind(int N) : par(N), sizes(N) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
      sizes[i] = 1;
    }
  }

  // データxが属する木の根を返す
  // O(logN)
  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  // xとyの木を併合
  void merge(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    // xとyの根が同じ(=同じ木にある)時はそのまま
    if (rx == ry)
      return;
    // 小を大にくっつける
    if (sizes[rx] < sizes[ry])
      swap(rx, ry);
    par[rx] = ry;
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  // 素集合のサイズ
  int size(int x) { return sizes[root(x)]; }
};

int main() {
  int N, Q;
  cin >> N >> Q;

  UnionFind tree(N);

  for (int i = 0; i < Q; i++) {
    int p, x, y;
    cin >> p >> x >> y;
    if (p == 0) {
      // xの木とyの木を併合する
      tree.merge(x, y);
    } else {
      if (tree.same(x, y)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
