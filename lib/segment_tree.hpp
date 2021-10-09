#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP 1

#include <math.h>
#include <vector>

using namespace std;
using ll = long long;

// 遅延セグメント木
// - 初期化: O(N)
// - apply: O(logN)
// - query: O(logN)
// op: 親になにをいれるか
// fa:
// mapping: applyするときに何をするか
// fp:
// モノイド(集合X, 二項演算op,fa,mapping,p
// 単位元ex,em)についてサイズnで構築 set(int i, X x), build():
// i番目の要素をxにセット。まとめてセグ木を構築する。O(n) apply(i,x): i 番目の要素を x
// に更新。O(log(n)) query(a,b):  [a,b) 全てにopを作用させた値を取得。O(log(n))
// https://algo-logic.info/segment-tree/#toc_id_3
//
// わかりやすい解説: https://tsutaj.hatenablog.com/entry/2017/03/30/224339
// template <typename X, typename M> struct LazySegTree {
//   using Op = function<X(X, X)>;
//   using FA = function<X(X, M)>;
//   using Mapping = function<M(M, M)>;
//   using FP = function<M(M, int)>;
//   int n;
//   Op op;
//   FA fa;
//   Mapping mapping;
//   FP fp;
//   const X ex;
//   const M em;
//   vector<X> dat;
//   vector<M> lazy;

//   LazySegTree(int n_, Op op_, FA fa_, Mapping mapping_, FP fp_, X ex_, M em_)
//       : n(), op(op_), fa(fa_), mapping(mapping_), fp(fp_), ex(ex_), em(em_), dat(n_ * 4, ex),
//         lazy(n_ * 4, em) {
//     int x = 1;
//     while (n_ > x)
//       x *= 2;
//     n = x;
//   }

//   int leef(int k) {
//     return k + n - 1;
//   }
//   int last_parent() {
//     return n - 2;
//   }
//   int first_child() {
//     return n - 1;
//   }
//   int parent(int child) {
//     return (child - 1) / 2;
//   }
//   int left_child(int parent) {
//     return parent * 2 + 1;
//   }
//   int right_child(int parent) {
//     return parent * 2 + 2;
//   }
//   // 初期化 O(N)
//   // 1. set()で葉に値を入れて
//   // 2. build()で親を更新
//   void set(int i, X x) {
//     dat[leef(i)] = x;
//   }
//   void build() {
//     for (int k = last_parent(); k >= 0; k--)
//       update(k);
//   }

//   void update(int k) {
//     dat[k] = op(dat[left_child(k)], dat[right_child(k)]);
//   }

//   // 遅延評価
//   void eval(int k, int len) {
//     if (lazy[k] == em) return; // 更新するものが無ければ終了
//     if (k < first_child()) {   // 葉でなければ子に伝搬
//       lazy[left_child(k)] = mapping(lazy[left_child(k)], lazy[k]);
//       lazy[right_child(k)] = mapping(lazy[right_child(k)], lazy[k]);
//     }
//     // 自身を更新
//     // dat[k] = lazy[k];
//     dat[k] = fa(dat[k], fp(lazy[k], len));
//     lazy[k] = em;
//   }

//   // a番目(0-index)の値をxに変更
//   void apply(int a, M x) {
//     a = leef(a); // 葉を更新
//     // FIXME: あってる？
//     // dat[a] = x;
//     dat[a] = mapping(lazy[a], x);
//     while (a > 0) { // 登りながら更新
//       a = parent(a);
//       update(a);
//     }
//   }

//   // [a, b)をxに更新
//   void apply(int a, int b, M x, int k = 0, int l = 0, int r = -1) {
//     if (r < 0) r = n; // 最初に呼び出されたときの[l, r)は [0, n)
//     eval(k, r - l);
//     if (a <= l && r <= b) { // 完全に内側の時
//       lazy[k] = mapping(lazy[k], x);
//       eval(k, r - l);
//     } else if (a < r && l < b) {                      // 一部区間が被る時
//       apply(a, b, x, left_child(k), l, (l + r) / 2);  // 左の子
//       apply(a, b, x, right_child(k), (l + r) / 2, r); // 右の子
//       update(k);
//     }
//   }

//   X query(int a, int b, int k = 0, int l = 0, int r = -1) {
//     if (r < 0) r = n; // 最初に呼び出されたときの[l, r)は [0, n)
//     eval(k, r - l);
//     if (r <= a || b <= l) { // 完全に外側の時
//       return ex;
//     } else if (a <= l && r <= b) { // 完全に内側の時
//       return dat[k];
//     } else { // 一部区間が被る時
//       X vl = query(a, b, left_child(k), l, (l + r) / 2);
//       X vr = query(a, b, right_child(k), (l + r) / 2, r);
//       return op(vl, vr);
//     }
//   }
// };

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
    log = pow(n, 2);
    _size = 1 << log;
    // int x = 1;
    // while (n_ > x)
    //   x *= 2;
    // n = x;
    dat = vector<S>(2 * size(), e());
    lazy = vector<F>(size(), id());
    // printf("log=%d, size=%ul\n", log, dat.size());
    // dat = vector<S>(n * 4, e());
    // lazy = vector<F>(n * 4, id());
  }

  int leef(int k) {
    return k + n - 1;
  }
  int last_parent() {
    return n - 2;
  }
  // int first_child() {
  // return n - 1;
  int size() {
    return _size;
  }
  // int parent(int child) {
  // return (child - 1) / 2;
  int parent(int k, int i) {
    return k >> i;
  }
  int left_child(int parent) {
    // return parent * 2 + 1;
    return parent * 2;
  }
  int right_child(int parent) {
    // return parent * 2 + 2;
    return parent * 2 + 1;
  }

  // 初期化 O(N)
  // やらなくてもよい
  // 葉に値を入れて親を更新
  void init(vector<S> v) {
    for (int i = 0; i < n; i++)
      dat[size() + i] = v[i];
    for (int i = size() - 1; i >= 1; i--) {
      update(i);
    }
  }

  // p番目(0-index)の値をxに変更
  void set(int p, S x) {
    assert(0 <= p && p < n);
    p += size();
    for (int i = log; i >= 1; i--)
      push(parent(p, i));
    dat[p] = x;
    for (int i = 1; i <= log; i++) // 登りながら更新
      update(parent(p, i));
  }

  // p番目(0-index)の値を取得
  S get(int p) {
    assert(0 <= p && p < n);
    p += size();
    for (int i = log; i >= 1; i--)
      push(parent(p, i));
    return dat[p];
  }

  // [l, r)のすべての要素の操作f での積(product)
  // O(logN)
  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();

    l += size();
    r += size();

    for (int i = log; i >= 1; i--) {
      if ((parent(l, i) << i) != l) push(parent(l, i));
      if ((parent(r, i) << i) != r) push(parent(r - 1, i));
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, dat[l++]);
      if (r & 1) smr = op(dat[--r], smr);
      l = parent(l, 1);
      r = parent(r, 1);
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
    for (int i = log; i >= 1; i--) // 登っていく
      push(parent(p, i));
    dat[p] = mapping(f, dat[p]);
    for (int i = 1; i <= log; i++) // 下っていく
      update(parent(p, i));
  }

  // 区間の要素に一括で F の要素 f を作用(x = f(x))
  // [l, r)に操作fを実行
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size();
    r += size();

    // 遅延評価
    // 登っていく
    for (int i = log; i >= 1; i--) {
      if ((parent(l, i) << i) != l) push(parent(l, i));
      if ((parent(r, i) << i) != r) push(parent(r - 1, i));
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        // l が奇数なら操作 f を作用させる
        if (l & 1) all_apply(l++, f);
        // r が奇数なら操作 f を作用させる
        if (r & 1) all_apply(--r, f);
        l = parent(l, 1);
        r = parent(r, 1);
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) { // 下っていく
      if ((parent(l, i) << i) != l) update(parent(l, i));
      if ((parent(r, i) << i) != r) update(parent(r - 1, i));
    }
  }

  // 子から親に演算結果を更新
  void update(int k) {
    dat[k] = op(dat[left_child(k)], dat[right_child(k)]);
  }

  // 操作 f を作用させる
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
};

#endif // SEGMENT_TREE_HPP