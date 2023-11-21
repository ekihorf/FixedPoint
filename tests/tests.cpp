#include <gtest/gtest.h>
#include <ostream>
#include "FixedPoint.h"

void PrintTo(const FixedPoint<int32_t, 4>& fp, std::ostream* os) {
    *os << fp.getRawVal();
}

TEST(General, Construction) {
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

TEST(General, ObjectSize) {
    EXPECT_EQ(sizeof(FixedPoint<uint32_t, 3>), sizeof(uint32_t));
    EXPECT_EQ(sizeof(FixedPoint<uint16_t, 3>), sizeof(uint16_t));
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

TEST(Operators, AssignAdd) {
    using FP = FixedPoint<int, 2>;

    FP a(1.23);
    a += FP(3.33);
    EXPECT_EQ(a, FP(4.56));
}

TEST(Operators, AssignSubtract) {
    using FP = FixedPoint<int, 2>;

    FP a(1.23);
    a -= FP(0.23);
    EXPECT_EQ(a, FP(1.0));
}

TEST(Operators, AssignMultiply) {
    using FP = FixedPoint<int32_t, 3>;

    FP a(1.23);
    a *= FP(4.56);
    EXPECT_EQ(a, FP(5.608));
}

TEST(Operators, AssignDivide) {
    using FP = FixedPoint<int32_t, 3>;

    FP a(23.0);
    a /= FP(9.0);
    EXPECT_EQ(a, FP(2.555));
}

TEST(Operators, Equality) {
    using FP = FixedPoint<int, 2>;

    ASSERT_TRUE(FP(1.23) == FP(1.23));
    ASSERT_FALSE(FP(1.23) == FP(1.24));

    ASSERT_TRUE(FP(1.23) != FP(1.24));
    ASSERT_FALSE(FP(1.23) != FP(1.23));
}

TEST(Operators, Comparison) {
    using FP = FixedPoint<int, 2>;

    ASSERT_TRUE(FP(1.23) > FP(1.22));
    ASSERT_TRUE(FP(-1.22) > FP(-1.23));
    ASSERT_FALSE(FP(1.23) > FP(1.23));
    ASSERT_FALSE(FP(1.23) > FP(1.24));

    ASSERT_TRUE(FP(1.23) >= FP(1.22));
    ASSERT_TRUE(FP(-1.22) >= FP(-1.23));
    ASSERT_TRUE(FP(1.23) >= FP(1.23));
    ASSERT_FALSE(FP(1.23) >= FP(1.24));

    ASSERT_TRUE(FP(1.22) < FP(1.23));
    ASSERT_TRUE(FP(-1.23) < FP(-1.22));
    ASSERT_FALSE(FP(1.23) < FP(1.23));
    ASSERT_FALSE(FP(1.24) < FP(1.23));

    ASSERT_TRUE(FP(1.22) <= FP(1.23));
    ASSERT_TRUE(FP(-1.23) <= FP(-1.22));
    ASSERT_TRUE(FP(1.23) <= FP(1.23));
    ASSERT_FALSE(FP(1.24) <= FP(1.23));
}
