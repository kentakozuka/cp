#include "lib/bellman_ford.hpp"
#include <gtest/gtest.h>

// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja
TEST(bellman_ford_1, BasicAssertions) {
  Graph g(4);
  g[0].push_back(Edge{1, 2});
  g[0].push_back(Edge{2, 3});
  g[1].push_back(Edge{2, -5});
  g[1].push_back(Edge{3, 1});
  g[2].push_back(Edge{3, 2});
  auto ret = bellman_ford(g, 0);
  EXPECT_EQ(ret.second, true);
  EXPECT_EQ(ret.first[0], 0);
  EXPECT_EQ(ret.first[1], 2);
  EXPECT_EQ(ret.first[2], -3);
  EXPECT_EQ(ret.first[3], -1);
}

TEST(bellman_ford_2, BasicAssertions) {
  Graph g(4);
  g[0].push_back(Edge{1, 2});
  g[0].push_back(Edge{2, 3});
  g[1].push_back(Edge{2, -5});
  g[1].push_back(Edge{3, 1});
  g[2].push_back(Edge{3, 2});
  g[3].push_back(Edge{1, 0});
  auto ret = bellman_ford(g, 0);
  EXPECT_EQ(ret.second, false);
}

TEST(bellman_ford_3, BasicAssertions) {
  Graph g(4);
  g[0].push_back(Edge{1, 2});
  g[0].push_back(Edge{2, 3});
  g[1].push_back(Edge{2, -5});
  g[1].push_back(Edge{3, 1});
  g[2].push_back(Edge{3, 2});
  auto ret = bellman_ford(g, 1);
  EXPECT_EQ(ret.second, true);
  EXPECT_EQ(ret.first[0], LLONG_MAX);
  EXPECT_EQ(ret.first[1], 0);
  EXPECT_EQ(ret.first[2], -5);
  EXPECT_EQ(ret.first[3], -3);
}