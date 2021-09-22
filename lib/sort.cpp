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
    swap(a[l], a[r]);
    l++;
    r--;
  }
  return l;
}

// O(N*logN)
void quick_sort(vector<int> &a, int i, int j) {
  if (i == j)
    return;
  int p = pivot(a, i, j);
  if (p != -1) {
    int k = partition(a, i, j, a[p]);
    quick_sort(a, i, k - 1);
    quick_sort(a, k, j);
  }
}

// O(N^2)
// バブルソートと比較して、値の交換回数が少ないため速くなる。
void selection_sort(vector<int> &a) {
  int min;
  for (int i = 0; i < a.size() - 1; i++) {
    int m = i;
    for (int j = i + 1; j < a.size(); j++) {
      if (a[j] < a[m]) {
        m = j;
      }
    }
    swap(a[i], a[m]);
  }
}

// O(N^2)
void bubble_sort(vector<int> &a) {
  for (int i = 0; i < (a.size() - 1); i++) {
    for (int j = (a.size() - 1); j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j - 1], a[j]);
      }
    }
  }
}

// O(N^2)
void insertion_sort(vector<int> &a) {
  for (int i = 1; i < a.size(); i++) {
    int k = a[i];
    int j = i - 1;
    while ((j >= 0) && (a[j] > k)) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = k;
  }
}

void merge(vector<int> &a, int left, int mid, int right) {
  // 左右の配列を作成
  vector<int> L, R;
  for (int i = left; i <= mid; i++)
    L.push_back(a[i]);
  for (int i = mid + 1; i <= right; i++)
    R.push_back(a[i]);

  L.push_back(INT_MAX);
  R.push_back(INT_MAX);

  // マージ
  int l = 0;
  int r = 0;
  for (int i = left; i <= right; i++) {
    if (L[l] <= R[r]) {
      a[i] = L[l];
      l++;
    } else {
      a[i] = R[r];
      r++;
    }
  }
}

void merge_sort(vector<int> &a, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

int main() {
  vector<int> v = {3, 2, 0, 5, 8, 3, 4, 1, 3, 2};
  vector<int> a;

  a.clear();
  copy(v.begin(), v.end(), back_inserter(a));
  quick_sort(a, 0, a.size() - 1);
  cout << "[";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";

  a.clear();
  copy(v.begin(), v.end(), back_inserter(a));
  cout << "[";
  selection_sort(a);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";

  a.clear();
  copy(v.begin(), v.end(), back_inserter(a));
  cout << "[";
  bubble_sort(a);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";

  a.clear();
  copy(v.begin(), v.end(), back_inserter(a));
  cout << "[";
  insertion_sort(a);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";

  a.clear();
  copy(v.begin(), v.end(), back_inserter(a));
  cout << "[";
  merge_sort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";
}
