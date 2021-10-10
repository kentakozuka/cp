#include "lib/combination.hpp"
#include <gtest/gtest.h>

TEST(nCr, BasicAssertions) {
  EXPECT_EQ(nCr(10, 0), 1);
  EXPECT_EQ(nCr(10, 1), 10);
  EXPECT_EQ(nCr(10, 3), 120);
  EXPECT_EQ(nCr(10, 9), 10);
  EXPECT_EQ(nCr(10, 10), 1);
}

TEST(nHr, BasicAssertions) {
  EXPECT_EQ(nHr(7, 3), 84);
}

TEST(BiCoef, BasicAssertions) {
  auto bc = BiCoef(1000000007, 510000);
  EXPECT_EQ(bc.com(100000, 50000), 149033233);
}