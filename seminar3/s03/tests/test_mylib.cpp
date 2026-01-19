#include <gtest/gtest.h>
#include "my_lib.h"
#include <vector>
#include <string>

// ==========================
// ТЕСТЫ ДЛЯ powN
// ==========================

TEST(PowNTests, NormalCases) {
    int v1 = my_lib::powN<int, 3>(2);          // 2^3 = 8
    double v2 = my_lib::powN<double, 2>(5.0);  // 5.0^2 = 25.0
    int v3 = my_lib::powN<int, 1>(-3);         // (-3)^1 = -3

    EXPECT_EQ(v1, 8);
    EXPECT_DOUBLE_EQ(v2, 25.0);
    EXPECT_EQ(v3, -3);
}

TEST(PowNTests, EdgePowerZeroAndBig) {
    // P = 0 — цикл не выполняется, результат остаётся 1
    int v0 = my_lib::powN<int, 0>(10);           // 10^0 = 1
    EXPECT_EQ(v0, 1);

    // Большая степень (int)
    int vBig = my_lib::powN<int, 5>(3);          // 3^5 = 243
    EXPECT_EQ(vBig, 243);

    // Вариант с double для надёжности
    double v0d   = my_lib::powN<double, 0>(10.0); // 10.0^0 = 1.0
    double vBigD = my_lib::powN<double, 3>(2.0);  // 2.0^3 = 8.0

    EXPECT_DOUBLE_EQ(v0d, 1.0);
    EXPECT_DOUBLE_EQ(vBigD, 8.0);
}


// ==========================
// ТЕСТЫ ДЛЯ shuffle
// ==========================

TEST(ShuffleTests, SimplePermutation) {
    std::string s = "abcd";
    std::vector<int> idx{2, 0, 3, 1};

    std::string res = my_lib::shuffle(s, idx);

    EXPECT_EQ(res, "bdac");
}

TEST(ShuffleTests, DuplicateIndices) {
    std::string s = "abcd";
    std::vector<int> idx{0, 0, 1, 1};

    std::string res;

    EXPECT_NO_THROW(res = my_lib::shuffle(s, idx));

    EXPECT_EQ(res, "bd  ");   // "b" перезаписывает "a"; "d" перезаписывает "c"
}


// ==========================
// ТЕСТЫ ДЛЯ pv (печать вектора)
// ==========================

TEST(PvTests, NonEmptyVectors) {
    std::vector<int> vi{1, 2, 3};
    std::vector<std::string> vs{"a", "b", "c"};

    EXPECT_NO_THROW(my_lib::pv<int>(vi));
    EXPECT_NO_THROW(my_lib::pv<std::string>(vs));
}

TEST(PvTests, EmptyVectors) {
    std::vector<int> vi_empty;
    std::vector<std::string> vs_empty;

    EXPECT_NO_THROW(my_lib::pv<int>(vi_empty));
    EXPECT_NO_THROW(my_lib::pv<std::string>(vs_empty));
}
