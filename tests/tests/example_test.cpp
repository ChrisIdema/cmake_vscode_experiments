/**
 * @file example_test.cpp
 * @brief Just an example test with google test.
 * @date 2022-04-11
 */

#include "gtest/gtest.h"


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


// TEST(HelloTest, BasicAssertionsFail)
// {
//     EXPECT_EQ(7 * 6, 43);
// }
