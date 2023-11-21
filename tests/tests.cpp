#include <gtest/gtest.h>
#include <ostream>
#include "FixedPoint.h"

void PrintTo(const FixedPoint<int32_t, 4>& fp, std::ostream* os) {
    *os << fp.getRawVal();
}

TEST(Construction, Construction) {
    FixedPoint<int, 4> a(1.23);
    FixedPoint<int, 4> b(12300, 4);
    FixedPoint<int, 4> c(123, 2);
    FixedPoint<int, 4> d(1230000, 6);
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(a, d);

    FixedPoint<int, 4> x(-56088, 4);
    FixedPoint<int, 4> y(-5.6088);
    EXPECT_EQ(x, y);
}

TEST(Operators, Minus) {
    using FP = FixedPoint<int, 2>;

    EXPECT_EQ(FP(-1.23), -FP(1.23));
}

TEST(Operators, Add) {
    using FP = FixedPoint<int, 2>;

    EXPECT_EQ(FP(1.23) + FP(2.22), FP(3.45));
}

TEST(Operators, Subtract) {
    using FP = FixedPoint<int, 2>;

    EXPECT_EQ(FP(1.23) - FP(2.22), FP(-0.99));
}

TEST(Operators, Multiply) {
    using FP = FixedPoint<int32_t, 3>;

    EXPECT_EQ(FP(1.23) * FP(-4.56), FP(-5.608));
    EXPECT_EQ(FP(1.56) * FP(21.483), FP(33.513));
}

TEST(Operators, Divide) {
    using FP = FixedPoint<int32_t, 3>;

    EXPECT_EQ(FP(1.23) / FP(-4.56), FP(-0.269));
    EXPECT_EQ(FP(23.0) / FP(9.0), FP(2.555));
}
