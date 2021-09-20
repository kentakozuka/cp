#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

// ランレングス圧縮
vector<pair<char, ll>> rl_encode(string &str) {
  int n = str.length();
  vector<pair<char, ll>> ret;
  for (int i = 0; i < n; i++) {
    // Count occurrences of current character
    int cnt = 1;
    while (i < n - 1 && str[i] == str[i + 1]) {
      cnt++;
      i++;
    }
    ret.push_back({str[i], cnt});
  }
  return ret;
}

// ランレングス圧縮の復元を行う
string decode(const vector<pair<char, int>> &code) {
  string ret = "";
  for (auto p : code) {
    for (int i = 0; i < p.second; i++) {
      ret.push_back(p.first);
    }
  }
  return ret;
}

int main() {
  string str = "tfffffdyyyeeehfj110000";
  cout << str << endl;

  auto e = rl_encode(str);
  for (int i = 0; i < e.size(); ++i) {
    cout << e[i].second << e[i].first;
  }
  cout << endl;
}