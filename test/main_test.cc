#include <gtest/gtest.h>

#if !defined(_SQEEZ_WIN)
TEST(MainTest, TestEnvironment) {
    EXPECT_EQ("GTEST", "GTEST");
}
#endif
