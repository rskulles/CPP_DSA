#include<gtest/gtest.h>
#include<vector>

#include "funcs.hpp"
TEST(HelloTest, BasicAssertions){
	EXPECT_STRNE("hello", "world");
	EXPECT_EQ(7*6,42);
	std::vector<int> a = {1,2,3};
	std::vector<int> b = {1,2,3};
	
	EXPECT_EQ(a, b);
}

TEST(HelloTest, AddOne){
	EXPECT_EQ(2, rs::add_one(1));
}
