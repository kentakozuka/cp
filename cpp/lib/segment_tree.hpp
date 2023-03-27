#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP 1

#include <math.h>
#include <vector>

using namespace std;
using ll = long long;

/*
https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp

S: data、各要素および区間取得結果の型
F: lazy、操作（写像）を表す値の型

S op(S a, S b)
  区間取得をどのような演算で行うかを定義

S mapping(F f, S x)
  操作 f を各ノードが持つ data の値 x に対して作用させる関数

F composition(F f, F g):
  g ∘ f
  既にこれまでの操作を溜めている lazy に対して、さらに新しい操作を追加する関数。
  g がこれまでの操作、f が後に追加する操作で、
  「その2つの操作を順に行うようなひとまとめの操作（合成写像）」を返す。
  順番に注意

S e()
  op の単位元を返す

F id()
  mapping における恒等写像を返す

*/
template <class S, class F> struct lazy_segtree {
  int n; // 葉の数
  int _size;
  int log;
  vector<S> dat;
  // S から S への写像の集合
  // その区間に対して行われた操作のうち、
  // まだ自身より下のノードに作用させていないものを保持する。
  vector<F> lazy;
  using Op = function<S(S, S)>;
  using Mapping = function<S(F, S)>;
  using Composition = function<F(F, F)>;
  using E = function<S()>;
  using Id = function<F()>;
  Op op;
  Mapping mapping;
  Composition composition;
  E e;
  Id id;

  lazy_segtree(int n_, Op op_, Mapping mapping_, Composition composition_, E e_, Id id_)
      : n(n_), op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_) {
    auto v = vector<S>(n, e());
    int x = 1;
    log = 0;
    while (x < n) {
      x <<= 1;
      log++;
    }
    // log = pow(n, 2);
    _size = 1 << log;
    printf("n=%d, log=%d, size=%d, dat=%d\n", n, log, _size, 2 * size());
    dat = vector<S>(2 * size(), e());
    lazy = vector<F>(size(), id());
  }

  int leef(int k) {
    return k + n - 1;
  }
  int last_parent() {
    return n - 2;
  }
  int size() {
    return _size;
  }
  int nth_parent(int k, int i) {
    return k >> i;
  }
  int left_child(int parent) {
    return parent * 2;
  }
  int right_child(int parent) {
    return parent * 2 + 1;
  }

  // 初期化 O(N)
  // やらなくてもよい
  // 葉に値を入れて親を更新
  void init(vector<S> v) {
    // 値を更新
    for (int i = 0; i < n; i++)
      dat[size() + i] = v[i];
    // 下から順にすべての親の値を計算
    for (int i = size() - 1; i >= 1; i--) {
      update(i);
    }
  }

  // p番目(0-index)の値をxに変更
  // 関数適用はしない
  void set(int p, S x) {
    assert(0 <= p && p < n);
    p += size();
    // 評価
    eval(p);
    // 更新(写像を作用しない)
    dat[p] = x;
    // 再計算
    calc(p);
  }

  // p番目(0-index)の値を取得
  S get(int p) {
    assert(0 <= p && p < n);
    p += size();
    // 評価
    eval(p);
    return dat[p];
  }

  // クエリ
  // [l, r)のすべての要素の操作f での積(product)
  // O(logN)
  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();

    l += size();
    r += size();

    // 評価
    eval(l, r);

    // クエリ
    // 下から順に対象となる区間を決定する
    S sml = e(), smr = e();
    while (l < r) {
      // l が右の子(奇数)なら計算する
      if (l & 1) sml = op(sml, dat[l++]);
      // r が右の子(奇数)なら計算する
      if (r & 1) smr = op(dat[--r], smr);
      l = nth_parent(l, 1);
      r = nth_parent(r, 1);
    }

    return op(sml, smr);
  }

  // 総積
  S all_prod() {
    return dat[1];
  }

  // pに操作fを実行
  void apply(int p, F f) {
    assert(0 <= p && p < n);
    p += size();
    // 評価
    eval(p);
    // 写像の作用
    dat[p] = mapping(f, dat[p]);
    // 再計算
    calc(p);
  }

  // [l, r)に操作fを実行
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size();
    r += size();

    // 評価
    eval(l, r);

    // 写像の作用
    auto lr = map(l, r, f);
    l = lr.first;
    r = lr.second;

    // 再計算
    calc(l, r);
  }

  // 子から親に演算結果を更新
  void update(int k) {
    dat[k] = op(dat[left_child(k)], dat[right_child(k)]);
  }

  // 操作 f を k に作用させる
  void all_apply(int k, F f) {
    // 操作 f をdat[k] の値 に対して作用させる
    dat[k] = mapping(f, dat[k]);
    // k が親なら写像を合成してlazy[k]に溜めておく
    if (k < size()) lazy[k] = composition(f, lazy[k]);
  }

  // 写像を子に伝播させる
  void push(int k) {
    all_apply(left_child(k), lazy[k]);
    all_apply(right_child(k), lazy[k]);
    lazy[k] = id(); // 恒等写像にリセット
  }

  // 写像適用
  pair<int, int> map(int l, int r, F f) {
    int l2 = l, r2 = r;
    // 下から順に f を作用させる
    while (l < r) {
      // l が右の子(奇数)なら操作 f を作用させる
      if (l & 1) all_apply(l++, f);
      // r が右の子(奇数)なら操作 f を作用させる
      if (r & 1) all_apply(--r, f);
      l = nth_parent(l, 1);
      r = nth_parent(r, 1);
    }
    l = l2;
    r = r2;
    return {l, r};
  }

  // 計算
  // 下から順に親をの値を計算する
  void calc(int k) {
    for (int i = 1; i <= log; i++)
      update(nth_parent(k, i));
  }

  // 区間計算
  // 下から順に親をの値を計算する
  void calc(int l, int r) {
    // 下から順に、再計算する
    for (int i = 1; i <= log; i++) {
      // 親 nth_parent(l, i) の左端の葉でないなら、再計算する
      // (左端の場合、子の値が親に入っている)
      if ((nth_parent(l, i) << i) != l) update(nth_parent(l, i));
      if ((nth_parent(r, i) << i) != r) update(nth_parent(r - 1, i));
    }
  }

  // 評価
  // 上から順に、溜まっている遅延評価分を反映し、子に伝播させる
  void eval(int k) {
    for (int i = log; i >= 1; i--)
      push(nth_parent(k, i));
  }

  // 区間評価
  // 上から順に、溜まっている遅延評価分を反映し、子に伝播させる
  void eval(int l, int r) {
    for (int i = log; i >= 1; i--) {
      // 親 nth_parent(l, i) の左端の葉でないなら、
      // 溜まっている遅延評価分を反映し、子に伝播させる
      // (左端の場合、子の値が親に入っている)
      if ((nth_parent(l, i) << i) != l) push(nth_parent(l, i));
      if ((nth_parent(r, i) << i) != r) push(nth_parent(r - 1, i));
    }
  }
};

#endif // SEGMENT_TREE_HPP