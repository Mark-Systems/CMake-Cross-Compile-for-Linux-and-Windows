#include "gtest/gtest.h"
#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../src/demo.hpp"

TEST(sample_test_case, sample_test)
{
    EXPECT_TRUE(true);
    Demo d;
    auto result = d.add(1,1);
    EXPECT_EQ(2,result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
