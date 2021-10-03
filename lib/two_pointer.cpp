#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, ll> Map;
ll N, K;
vector<ll> A;
ll ans = 0;
ll cnt = 0;

void add(ll right) {
  Map[A[right]] += 1;
  if (Map[A[right]] == 1) {
    cnt++;
  }
}

void remove(ll left) {
  Map[A[left]] -= 1;
  if (Map[A[left]] == 0) {
    cnt--;
  }
}

// 条件を満たすかどうか
bool is_ok(ll left, ll right) {
  if (cnt <= K) {
    ans = max(ans, right - left + 1);
    return true;
  } else {
    return false;
  }
}

// 尺取法
// O(N)
// 条件を満たすような区間をすべて求めることができる
void two_pointer() {
  ll n = A.size();
  ll right = -1;
  for (ll left = 0; left < n; left++) {
    while (right < n) {
      // 条件を満たしているかどうかを判定する
      // 満たしている:    right を右にずらす
      // 満たしていない:  left を右にずらす
      if (left <= right && !is_ok(left, right)) break;
      right++;
      // Write add process.
      add(right);
    }
    // Write remove process.
    remove(left);
  }
}

// https://atcoder.jp/contests/typical90/tasks/typical90_ah
int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; i++) {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  two_pointer();

  cout << ans << endl;
  return 0;
}