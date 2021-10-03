#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 順列（文字列）
// O(n!)
void print_string_permutations(string str) {
  sort(str.begin(), str.end());
  do {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));
}

// 順列（数値）
// O(n!)
void print_int_permutations(vector<int> nums) {
  sort(nums.begin(), nums.end());
  do {
    for (auto num : nums) {
      cout << num << " ";
    }
    cout << "\n";
    // 順列の最後になるまで one_case を並び替えながらループ
  } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
  print_string_permutations("str");
  print_int_permutations({1, 2, 3});
  return 0;
}
