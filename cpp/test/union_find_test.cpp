#include "lib/union_find.hpp"
#include <gtest/gtest.h>

TEST(UnionFind, BasicAssertions) {
  // https://atcoder.jp/contests/atc001/tasks/unionfind_a
  int N = 8;
  UnionFind uf(N);
  uf.merge(1, 2);
  uf.merge(3, 2);
  EXPECT_EQ(uf.same(1, 3), true);
  EXPECT_EQ(uf.same(1, 4), false);
  uf.merge(2, 4);
  EXPECT_EQ(uf.same(4, 1), true);
  uf.merge(4, 2);
  uf.merge(0, 0);
  EXPECT_EQ(uf.same(0, 0), true);
}