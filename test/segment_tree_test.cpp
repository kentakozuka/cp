#include "lib/segment_tree.hpp"
#include <gtest/gtest.h>

const int INF = numeric_limits<int>::max();

// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp

// 区間加算・区間最小取得, 初期化 O(N*longN)
TEST(lazy_segtree, RAQ_RMQ) {
  using S = int;
  using F = int;
  auto op = [](S a, S b) -> S { return min(a, b); };
  auto e = []() -> S { return INF; };
  auto mapping = [](F f, S x) -> S { return x + f; };
  auto composition = [](F f, F g) -> F { return f + g; };
  auto id = []() -> F { return 0; };
  lazy_segtree<S, F> st(5, op, mapping, composition, e, id);

  st.set(0, 1);
  st.set(1, 2);
  st.set(2, 3);
  EXPECT_EQ(st.prod(0, 2 + 1), 1);
  EXPECT_EQ(st.prod(1, 2 + 1), 2);
  st.apply(0, 1);
  EXPECT_EQ(st.prod(0, 2 + 1), 2);
  EXPECT_EQ(st.prod(1, 2 + 1), 2);
  st.apply(0, 2 + 1, 1);
  EXPECT_EQ(st.prod(0, 2 + 1), 3);
  EXPECT_EQ(st.prod(1, 2 + 1), 3);
}

// 区間加算・区間最小取得, 初期化 O(longN)
TEST(lazy_segtree, RAQ_RMQ_init) {
  using S = int;
  using F = int;
  auto op = [](S a, S b) -> S { return min(a, b); };
  auto e = []() -> S { return INF; };
  auto mapping = [](F f, S x) -> S { return x + f; };
  auto composition = [](F f, F g) -> F { return f + g; };
  auto id = []() -> F { return 0; };
  lazy_segtree<S, F> st(5, op, mapping, composition, e, id);
  auto v = vector<S>{1, 2, 3, INF, INF};
  st.init(v);
  EXPECT_EQ(st.prod(0, 2 + 1), 1);
  EXPECT_EQ(st.prod(1, 2 + 1), 2);
}

// 区間変更・区間和取得
TEST(lazy_segtree, RUQ_RSQ) {
  struct S {
    int value;
    int size;
  };
  using F = int;
  auto op = [](S a, S b) -> S { return {a.value + b.value, a.size + b.size}; };
  auto e = []() -> S { return {0, 0}; };
  auto mapping = [](F f, S x) -> S {
    if (f != 0) x.value = f * x.size;
    return x;
  };
  auto composition = [](F f, F g) -> F { return (f == 0 ? g : f); };
  auto id = []() -> F { return 0; };
  lazy_segtree<S, F> st(5, op, mapping, composition, e, id);

  st.set(0, {1, 1});
  st.set(1, {2, 1});
  st.set(2, {3, 1});
  EXPECT_EQ(st.prod(0, 2 + 1).value, 6);
  EXPECT_EQ(st.prod(0, 4 + 1).value, 6);
  EXPECT_EQ(st.prod(1, 2 + 1).value, 5);
  st.set(0, {2, 1});
  EXPECT_EQ(st.prod(0, 2 + 1).value, 7);
}

// 区間加算・区間和取得
TEST(lazy_segtree, RAQ_RSQ) {
  struct S {
    int value;
    int size;
  };
  using F = int;
  auto op = [](S a, S b) -> S { return {a.value + b.value, a.size + b.size}; };
  auto e = []() -> S { return {0, 0}; };
  auto mapping = [](F f, S x) -> S { return {x.value + x.size * f, x.size}; };
  auto composition = [](F f, F g) -> F { return f + g; };
  auto id = []() -> F { return 0; };
  lazy_segtree<S, F> st(5, op, mapping, composition, e, id);

  st.set(0, {1, 1});
  st.set(1, {2, 1});
  st.set(2, {3, 1});
  EXPECT_EQ(st.prod(0, 2 + 1).value, 6);
  EXPECT_EQ(st.prod(0, 4 + 1).value, 6);
  EXPECT_EQ(st.prod(1, 2 + 1).value, 5);

  st.set(3, {0, 1});
  st.set(4, {0, 1});
  EXPECT_EQ(st.prod(0, 2 + 1).value, 6);
  EXPECT_EQ(st.prod(0, 4 + 1).value, 6);
  EXPECT_EQ(st.prod(1, 2 + 1).value, 5);
  st.apply(0, 4 + 1, 1);
  EXPECT_EQ(st.prod(0, 4 + 1).value, 11);
  EXPECT_EQ(st.get(0).value, 2);
}