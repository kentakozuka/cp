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

using ll = long long;
using ld = long double;

// 中央値
// == 各要素からの距離が最も小さい数値
// O(N log N)
ld median(vector<ll> nums) {
  size_t size = nums.size();
  if (size == 0) {
    return 0;
  } else {
    sort(nums.begin(), nums.end());
    if (size % 2 == 0) {
      return (nums[size / 2 - 1] + nums[size / 2]) / 2;
    } else {
      return nums[size / 2];
    }
  }
}
