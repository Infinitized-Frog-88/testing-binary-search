#include <chrono>
#include <vector>
#include <thread>
#include <atomic>
#include "binsearch.h"
#include "gtest/gtest.h"

const int kTimeoutMs = 1000;

template <typename Func>
void RunWithHardTimeout(Func&& func, int timeout_ms) {
    std::atomic<bool> completed{false};
    std::thread test_thread([&] {
        func();
        completed = true;
    });

    auto start_time = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(timeout_ms)) {
        if (completed) {
            test_thread.join();
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    test_thread.detach();
    throw std::runtime_error("Test timed out");
}

TEST(BinSearchTest, ElementFound) {
    EXPECT_NO_THROW(RunWithHardTimeout([] {
        int32_t array[] = {1, 4, 4, 88, 2024};
        int32_t n = sizeof(array) / sizeof(array[0]);

        EXPECT_TRUE(BinSearch(array, n, 2024));
        EXPECT_TRUE(BinSearch(array, n, 1));
        EXPECT_TRUE(BinSearch(array, n, 88));
    }, kTimeoutMs));
}

TEST(BinSearchTest, ElementNotFound) {
    EXPECT_NO_THROW(RunWithHardTimeout([] {
        int32_t array[] = {1, 3, 4, 11, 2024};
        int32_t n = sizeof(array) / sizeof(array[0]);

        EXPECT_FALSE(BinSearch(array, n, 2));
        EXPECT_FALSE(BinSearch(array, n, 0));
        EXPECT_FALSE(BinSearch(array, n, 10));
    }, kTimeoutMs));
}

TEST(BinSearchTest, TimeTest) {
    EXPECT_NO_THROW(RunWithHardTimeout([] {
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
    }, kTimeoutMs));
}

TEST(BinSearchTest, EmptyArray) {
    EXPECT_NO_THROW(RunWithHardTimeout([] {
        int32_t array[] = {};
        int32_t n = 0;
        EXPECT_FALSE(BinSearch(array, n, 88));
    }, kTimeoutMs));
}

TEST(BinSearchTest, SingleElementArray) {
    EXPECT_NO_THROW(RunWithHardTimeout([] {
        int32_t array[] = {88};
        int32_t n = 1;
        EXPECT_TRUE(BinSearch(array, n, 88));
        EXPECT_FALSE(BinSearch(array, n, 8));
    }, kTimeoutMs));
}
