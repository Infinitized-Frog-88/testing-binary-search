#include <chrono>
#include <vector>
#include "binsearch.h"
#include "gtest/gtest.h"

TEST(BinSearchTest, ElementFound) {
    int32_t array[] = {1, 4, 4, 88, 2024};
    int32_t n = sizeof(array) / sizeof(array[0]);

    EXPECT_TRUE(BinSearch(array, n, 2024));
    EXPECT_TRUE(BinSearch(array, n, 1));
    EXPECT_TRUE(BinSearch(array, n, 88));
}

TEST(BinSearchTest, ElementNotFound) {
    int32_t array[] = {1, 3, 4, 11, 2024};
    int32_t n = sizeof(array) / sizeof(array[0]);

    EXPECT_FALSE(BinSearch(array, n, 2));
    EXPECT_FALSE(BinSearch(array, n, 0));
    EXPECT_FALSE(BinSearch(array, n, 10));
}

TEST(BinSearchTest, TimeTest) {
    const int32_t n = 1000000;
    std::vector<int32_t> array(n);
    for (int32_t i = 0; i < n; ++i) {
        array[i] = i * 2;
    }

    int32_t x = array[n - 1];
    
    auto start = std::chrono::steady_clock::now();
    bool found = BinSearch(array.data(), n, x);
    auto end = std::chrono::steady_clock::now();
    
    std::chrono::duration<double> duration = end - start;
    EXPECT_TRUE(found);
    EXPECT_LT(duration.count(), 0.001);
}

TEST(BinSearchTest, EmptyArray) {
    int32_t array[] = {};
    int32_t n = 0;
    EXPECT_FALSE(BinSearch(array, n, 88));
}

TEST(BinSearchTest, SingleElementArray) {
    int32_t array[] = {88};
    int32_t n = 1;
    EXPECT_TRUE(BinSearch(array, n, 88));
    EXPECT_FALSE(BinSearch(array, n, 8));
}
