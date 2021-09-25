#include "lib/mod.hpp"
#include <gtest/gtest.h>

const int MOD = 1000000007;

TEST(mod, BasicAssertions) {
  EXPECT_EQ(mod(3, 2), 1);
  EXPECT_EQ(mod(-3, 2), 1);
}

TEST(moddiv, BasicAssertions) {
  EXPECT_EQ(moddiv(12345678900000, 100000, MOD), 123456789);
}