#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// エラトステネスの篩
// Nまでの素数を列挙する.
// O(N*log logN)
vector<ll> eratosthenes(const ll N) {
  vector<bool> is_prime(N + 1);
  for (ll i = 0; i <= N; i++) {
    is_prime[i] = true;
  }
  vector<ll> P;
  for (ll i = 2; i <= N; i++) {
    if (is_prime[i]) {
      for (ll j = 2 * i; j <= N; j += i) {
        is_prime[j] = false;
      }
      P.emplace_back(i);
    }
  }
  return P;
}

int main() {
  ll N = 100;
  vector<ll> primes = eratosthenes(N);
  for (ll i = 0; i < primes.size(); i++) {
    cout << primes[i] << endl;
  }
  return 0;
}