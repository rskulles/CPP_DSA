#include "funcs.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
  // Testing vector equallity will help later...
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {1, 2, 3};
  EXPECT_EQ(a, b)<<"Vectors a and b are different";
}

TEST(HelloTest, AddOne) { EXPECT_EQ(2, rs::add_one(1)); }

