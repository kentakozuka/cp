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
typedef long double ld;

// O(j - i +1)
int pivot(vector<int> &a, int i, int j) {
  int k = i + 1;
  while (k <= j && a[i] == a[k])
    k++;
  if (k > j)
    return -1;
  if (a[i] >= a[k])
    return i;
  return k;
}

// O(j - i +1)
int partition(vector<int> &a, int i, int j, int x) {
  int l = i, r = j;
  // 検索が交差するまで繰り返します
  while (l <= r) {
    // 軸要素以上のデータを探します
    while (l <= j && a[l] < x)
      l++;
    // 軸要素未満のデータを探します
    while (r >= i && a[r] >= x)
      r--;
    if (l > r)
      break;
    int t = a[l];
    a[l] = a[r];
    a[r] = t;
    l++;
    r--;
  }
  return l;
}

// O(N*logN)
void quickSort(vector<int> &a, int i, int j) {
  if (i == j)
    return;
  int p = pivot(a, i, j);
  if (p != -1) {
    int k = partition(a, i, j, a[p]);
    quickSort(a, i, k - 1);
    quickSort(a, k, j);
  }
}

int main() {
  vector<int> a = {3, 2, 0, 5, 8, 3, 4, 1, 3, 2};
  quickSort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
}
