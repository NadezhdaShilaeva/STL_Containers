#ifndef CRATIONAL
#define CRATIONAL
#include <iostream>

int gcd(int u, int v)
{
    while (v != 0)
    {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

class CRational
{
public:
    explicit CRational(int numerator = 0, unsigned denominator = 1)
        : numerator_(numerator), denominator_(denominator)
    {
        unsigned gcd_ = gcd(numerator_, denominator_);
        numerator_ /= gcd_;
        denominator_ /= gcd_;
    }
    CRational(const CRational &other)
        : numerator_(other.numerator_), denominator_(other.denominator_) {}
    ~CRational() {}
    CRational &operator=(const CRational &other)
    {
        if (&other == this)
        {
            return *this;
        }

        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        return *this;
    }
    bool operator==(const CRational &rhs)
    {
        return numerator_ * rhs.denominator_ == rhs.numerator_ * denominator_;
    }
    bool operator!=(const CRational &rhs)
    {
        return !(*this).operator==(rhs);
    }
    bool operator<(const CRational &rhs)
    {
        return numerator_ * rhs.denominator_ < rhs.numerator_ * denominator_;
    }
    bool operator>(const CRational &rhs)
    {
        return !(*this < rhs) && *this != rhs;
    }
    bool operator<=(const CRational &rhs)
    {
        return !(*this > rhs);
    }
    bool operator>=(const CRational &rhs)
    {
        return !(*this < rhs);
    }
    int numerator() const
    {
        return numerator_;
    }
    unsigned denominator() const
    {
        return denominator_;
    }
    friend std::ostream &operator<<(std::ostream &stream, const CRational &value);

private:
    int numerator_;
    unsigned denominator_;
};

std::ostream &operator<<(std::ostream &stream, const CRational &value)
{
    stream << value.numerator() << '/' << value.denominator();
    return stream;
}

#endif // CRATIONAL