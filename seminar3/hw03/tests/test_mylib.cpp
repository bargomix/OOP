#include "my_lib.h"      // наша библиотека
#include <gtest/gtest.h> // GoogleTest
#include <vector>
#include <string>

// ==================== powN ====================

TEST(PowNTestSuite, NormalCases) {
    int v1 = my_lib::powN<int, 3>(2);         // 2^3 = 8
    double v2 = my_lib::powN<double, 2>(5.0); // 5^2 = 25.0
    int v3 = my_lib::powN<int, 1>(-3);        // (-3)^1 = -3

    EXPECT_EQ(v1, 8);
    EXPECT_DOUBLE_EQ(v2, 25.0);
    EXPECT_EQ(v3, -3);
}

TEST(PowNTestSuite, EdgePowerZeroAndBig) {
    int v0   = my_lib::powN<int, 0>(10); // 10^0 = 1
    int vBig = my_lib::powN<int, 5>(3);  // 3^5 = 243

    EXPECT_EQ(v0, 1);
    EXPECT_EQ(vBig, 243);
}

// новый тест: отрицательное основание и чётная степень
TEST(PowNTestSuite, NegativeBaseEvenPower) {
    int v = my_lib::powN<int, 4>(-2); // (-2)^4 = 16
    EXPECT_EQ(v, 16);
}

// новый тест: отрицательное основание и нечётная степень
TEST(PowNTestSuite, NegativeBaseOddPower) {
    int v = my_lib::powN<int, 3>(-2); // (-2)^3 = -8
    EXPECT_EQ(v, -8);
}

// новый тест: использование степени по умолчанию P = 2
TEST(PowNTestSuite, DefaultPowerTwo) {
    int v = my_lib::powN<int>(3); // 3^2 = 9
    EXPECT_EQ(v, 9);
}

// ==================== shuffle ====================

TEST(ShuffleTestSuite, SimplePermutation) {
    std::string s = "abcd";
    std::vector<int> idx{2, 0, 3, 1};

    std::string res = my_lib::shuffle(s, idx);

    EXPECT_EQ(res, "bdac");
}

TEST(ShuffleTestSuite, DuplicateIndices) {
    std::string s = "abcd";
    std::vector<int> idx{0, 0, 1, 1};

    std::string res;
    EXPECT_NO_THROW(res = my_lib::shuffle(s, idx));

    EXPECT_EQ(res, "bd  ");
}

TEST(ShuffleTestSuite, IndexOutOfBoundsHigh) {
    std::string s = "abc";
    std::vector<int> idx{0, 5, 1}; // индекс 5 выходит за диапазон

    EXPECT_NO_THROW({
        std::string res = my_lib::shuffle(s, idx);
    });
}

TEST(ShuffleTestSuite, NegativeIndex) {
    std::string s = "abcd";
    std::vector<int> idx{-1, 2, 1, 0}; // -1 недопустимо

    EXPECT_NO_THROW({
        std::string res = my_lib::shuffle(s, idx);
    });
}

TEST(ShuffleTestSuite, WrongIndexVectorSize) {
    std::string s = "abcd";
    std::vector<int> idx{0, 1}; // idx слишком короткий

    EXPECT_NO_THROW({
        std::string res = my_lib::shuffle(s, idx);
    });
}

// новый тест: тождественная перестановка
TEST(ShuffleTestSuite, IdentityPermutation) {
    std::string s = "abcdef";
    std::vector<int> idx{0, 1, 2, 3, 4, 5};

    std::string res = my_lib::shuffle(s, idx);

    EXPECT_EQ(res, "abcdef");
}

// новый тест: пустая строка
TEST(ShuffleTestSuite, EmptyString) {
    std::string s;
    std::vector<int> idx;

    std::string res;
    EXPECT_NO_THROW(res = my_lib::shuffle(s, idx));
    EXPECT_EQ(res, "");
}

// ==================== pv ====================

TEST(PvTestSuite, NonEmptyVectors) {
    std::vector<int> vi{1, 2, 3};
    std::vector<std::string> vs{"a", "b", "c"};

    EXPECT_NO_THROW(my_lib::pv(vi));
    EXPECT_NO_THROW(my_lib::pv(vs));
}

TEST(PvTestSuite, EmptyVectors) {
    std::vector<int> vi_empty;
    std::vector<std::string> vs_empty;

    EXPECT_NO_THROW(my_lib::pv(vi_empty));
    EXPECT_NO_THROW(my_lib::pv(vs_empty));
}

// новый тест: большой вектор
TEST(PvTestSuite, LargeVector) {
    std::vector<int> big;
    for (int i = 0; i < 100; ++i) {
        big.push_back(i);
    }
    EXPECT_NO_THROW(my_lib::pv(big));
}

// ==================== операции add/sub/mul/divide/apply_op ====================

TEST(OpsTestSuite, BasicIntOperations) {
    int a = 10;
    int b = 5;

    int s = my_lib::add<int>(a, b);
    int d = my_lib::sub<int>(a, b);
    int m = my_lib::mul<int>(a, b);
    int q = my_lib::divide<int>(a, b);

    EXPECT_EQ(s, 15);
    EXPECT_EQ(d, 5);
    EXPECT_EQ(m, 50);
    EXPECT_EQ(q, 2);
}

TEST(OpsTestSuite, DivideByZero) {
    int a = 10;
    int b = 0;

    int q = my_lib::divide<int>(a, b);

    EXPECT_EQ(q, 0);
}

TEST(OpsTestSuite, ApplyOpWithLibraryOps) {
    int a = 3;
    int b = 4;

    int sum  = my_lib::apply_op<int>(a, b, my_lib::add<int>);
    int prod = my_lib::apply_op<int>(a, b, my_lib::mul<int>);

    EXPECT_EQ(sum, 7);
    EXPECT_EQ(prod, 12);
}

// новый тест: операции над double
TEST(OpsTestSuite, BasicDoubleOperations) {
    double a = 7.5;
    double b = 2.5;

    double s = my_lib::add<double>(a, b);
    double d = my_lib::sub<double>(a, b);
    double m = my_lib::mul<double>(a, b);
    double q = my_lib::divide<double>(a, b);

    EXPECT_DOUBLE_EQ(s, 10.0);
    EXPECT_DOUBLE_EQ(d, 5.0);
    EXPECT_DOUBLE_EQ(m, 18.75);
    EXPECT_DOUBLE_EQ(q, 3.0);
}

// новый тест: деление с отрицательными числами
TEST(OpsTestSuite, DivideNegativeNumbers) {
    int a = -9;
    int b = 3;
    int c = -3;

    EXPECT_EQ(my_lib::divide<int>(a, b), -3);
    EXPECT_EQ(my_lib::divide<int>(a, c), 3);
}

// новый тест: apply_op с лямбдой (нестандартная операция)
TEST(OpsTestSuite, ApplyOpWithLambda) {
    int a = 2;
    int b = 5;

    auto custom_op = [](int x, int y) {
        // какое-то своё правило: x * y + 1
        return x * y + 1;
    };

    int res = my_lib::apply_op<int>(a, b, custom_op);
    EXPECT_EQ(res, 11); // 2 * 5 + 1
}

// ==================== main для GoogleTest ====================

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
