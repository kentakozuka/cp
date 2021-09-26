#include "lib/kruscal.hpp"
#include <gtest/gtest.h>

TEST(kruskal, BasicAssertions) {
  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
  int V = 6;
  int E = 9;
  vector<Edge> es(E);
  es[0] = Edge{0, 1, 1};
  es[1] = Edge{0, 2, 3};
  es[2] = Edge{1, 2, 1};
  es[3] = Edge{1, 3, 7};
  es[4] = Edge{2, 4, 1};
  es[5] = Edge{1, 4, 3};
  es[6] = Edge{3, 4, 1};
  es[7] = Edge{3, 5, 1};
  es[8] = Edge{4, 5, 6};
  EXPECT_EQ(kruskal(V, es), 5);
}