#include "lib/pow.hpp"
#include <gtest/gtest.h>

TEST(pow, BasicAssertions) {
  // POW
  EXPECT_EQ(POW(2, 10), 1024);
  EXPECT_EQ(POW(5, 8), 390625);
}