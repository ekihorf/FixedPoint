#pragma once
#include <cstdint>

template <typename T, unsigned P>
class FixedPoint
{
public:
    inline constexpr FixedPoint(double val)
    {
        m_raw = static_cast<T>(val * SCALE + (val < 0 ? -0.5 : 0.5));
    }

    inline constexpr FixedPoint(T val)
    {
        m_raw = val * SCALE;
    }

    inline constexpr FixedPoint(T raw_val, int precision)
    {
        if (precision == P) {
            m_raw = raw_val;
        } else if (precision < P) {
            m_raw = raw_val * pow10(P - precision);
        } else if (precision > P) {
            m_raw = raw_val / pow10(precision - P);
        }
    }

    inline constexpr FixedPoint operator-() const
    {
        return FixedPoint<T, P>(-m_raw, P);
    }

    inline constexpr FixedPoint operator+(const FixedPoint& other) const
    {
        return FixedPoint<T, P>(m_raw + other.m_raw, P);
    }

    inline constexpr FixedPoint operator-(const FixedPoint& other) const
    {
        return FixedPoint<T, P>(m_raw - other.m_raw, P);
    }

    inline constexpr FixedPoint operator*(const FixedPoint& other) const
    {
        return FixedPoint<T, P>(m_raw * other.m_raw / SCALE, P);
    }

    inline constexpr FixedPoint operator/(const FixedPoint& other) const
    {
        return FixedPoint<T, P>(m_raw * SCALE / other.m_raw, P);
    }

    inline constexpr void operator+=(const FixedPoint& other)
    {
        m_raw += other.m_raw;
    }

    inline constexpr void operator-=(const FixedPoint& other)
    {
        m_raw -= other.m_raw;
    }

    inline constexpr void operator*=(const FixedPoint& other)
    {
        m_raw *= other.m_raw;
        m_raw /= SCALE;
    }

    inline constexpr void operator/=(const FixedPoint& other)
    {
        m_raw *= SCALE;
        m_raw /= other.m_raw;
    }

    inline constexpr bool operator>(const FixedPoint& other) const
    {
        return m_raw > other.m_raw;
    }

    inline constexpr bool operator<(const FixedPoint& other) const
    {
        return m_raw < other.m_raw;
    }

    inline constexpr bool operator>=(const FixedPoint& other) const
    {
        return m_raw >= other.m_raw;
    }

    inline constexpr bool operator<=(const FixedPoint& other) const
    {
        return m_raw <= other.m_raw;
    }

    inline constexpr bool operator==(const FixedPoint& other) const
    {
        return m_raw == other.m_raw;
    }

    inline constexpr bool operator!=(const FixedPoint& other) const
    {
        return m_raw != other.m_raw;
    }

    inline constexpr T getRawVal() const
    {
        return m_raw;
    }

private:
    inline static constexpr T pow10(T exp)
    {
        T res = 1;
        while (exp--) {
            res *= 10;
        }
        return res;
    }

    T m_raw;
    static constexpr T SCALE{pow10(P)};
};

using Fixed32_2 = FixedPoint<int32_t, 2>;
using Fixed32_3 = FixedPoint<int32_t, 3>;
using Fixed64_3 = FixedPoint<int64_t, 3>;
using Fixed64_6 = FixedPoint<int64_t, 6>;