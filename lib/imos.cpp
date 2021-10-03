#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// いもす法
// Imos
// verify: https://atcoder.jp/contests/typical90/tasks/typical90_ab
int main() {
  int N;
  cin >> N;

  vector<vector<int>> grid(1001, vector<int>(1001, 0));
  for (int i = 0; i < N; i++) {
    int tlx, tly, trx, ttry;
    cin >> tlx >> tly >> trx >> ttry;
    grid[tlx][tly] += 1;   // 左下
    grid[trx][tly] += -1;  // 右下
    grid[tlx][ttry] += -1; // 左上
    grid[trx][ttry] += 1;  // 右上
  }
  // x方向
  for (int i = 0; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      grid[j][i] = grid[j - 1][i] + grid[j][i];
    }
  }
  for (int i = 0; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      grid[i][j] = grid[i][j - 1] + grid[i][j];
    }
  }
  vector<int> area(N, 0);
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      if (grid[i][j] >= 1) area[grid[i][j] - 1] += 1;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << area[i] << endl;
  }
  return 0;
}
