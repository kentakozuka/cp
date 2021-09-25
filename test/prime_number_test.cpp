#include "lib/prime_number.hpp"
#include <gtest/gtest.h>

TEST(prime_number, BasicAssertions) {
  // is_prime
  EXPECT_EQ(is_prime(2), true);
  EXPECT_EQ(is_prime(3), true);
  EXPECT_EQ(is_prime(4), false);
  EXPECT_EQ(is_prime(1000000007), true);
}