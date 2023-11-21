#pragma once

template <typename T, unsigned P>
class FixedPoint
{
public:
    inline constexpr FixedPoint(double val)
    {
        m_raw = static_cast<T>(val * SCALE + (val < 0 ? -0.5 : 0.5));
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

    }

    inline constexpr void operator-=(const FixedPoint& other)
    {

    }

    inline constexpr void operator*=(const FixedPoint& other)
    {

    }

    inline constexpr void operator/=(const FixedPoint& other)
    {

    }

    inline constexpr bool operator>(const FixedPoint& other) const
    {
        return false;
    }

    inline constexpr bool operator<(const FixedPoint& other) const
    {
        return false;
    }

    inline constexpr bool operator>=(const FixedPoint& other) const
    {
        return false;
    }

    inline constexpr bool operator<=(const FixedPoint& other) const
    {
        return false;
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