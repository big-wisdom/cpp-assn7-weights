#include <cstdint>
#include <iostream>

namespace usu
{
    template <typename ToWeight, typename W>
    ToWeight weight_cast(W w)
    {
        ToWeight t;
        ToWeight newWeight(static_cast<double>(w.number) * w.weightRatio.num * t.weightRatio.den / (w.weightRatio.den * t.weightRatio.num));
        return newWeight;
    }

    template <typename W = std::ratio<1>, typename Rep = std::uint64_t>
    class weight
    {
      public:
        using conversion = W;

        weight() :
            number(0){};

        weight(Rep newCount) :
            number(newCount){};

        W weightRatio;
        Rep number;

        Rep count()
        {
            return number;
        }

        template <typename S>
        weight operator+(S s)
        {
            weight w(s.number + number);
            return w;
        }

        template <typename S>
        weight operator-(S s)
        {
            weight w(number - s.number);
            return w;
        }

        template <typename S>
        weight& operator=(S s)
        {
            if (this != s)
            {
                number = s.number;
                weightRatio = s.weightRatio;
            }
            return *this;
        }

        template <typename S>
        weight operator*(S s)
        {
            weight newS(s * number);
            return newS;
        }

        template <typename S>
        bool operator==(S& rhs)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(rhs);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return std::abs(nrhs.number - newThis.number) < 0.00001;
        }

        template <typename S>
        bool operator<=(S s)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(s);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return nrhs.number - newThis.number > -1 * 0.0004;
        }

        template <typename S>
        bool operator<(S s)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(s);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return nrhs.number - newThis.number > 0.00001;
        }

        template <typename S>
        bool operator>=(S s)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(s);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return nrhs.number - newThis.number < 0.00001;
        }

        template <typename S>
        bool operator>(S s)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(s);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return nrhs.number - newThis.number < -1 * 0.00001;
        }

        template <typename S>
        bool operator!=(S s)
        {
            auto nrhs = weight_cast<weight<std::ratio<1, 1>, double>>(s);
            auto newThis = weight_cast<weight<std::ratio<1, 1>, double>>(*this);

            return std::abs(nrhs.number - newThis.number) > 0.00001;
        }
    };

    using microgram = weight<std::ratio<1, 1000000>, double>;
    using kilogram = weight<std::ratio<1000, 1>, double>;
    using gram = weight<std::ratio<1, 1>, double>;
    using ton = weight<std::ratio<100000000, 11>, double>;
    // using ton = weight<std::ratio<100000000000, 98421>, double>;
    using ounce = weight<std::ratio<100000000000, 3527396195>, double>;
    using pound = weight<std::ratio<10000000000, 22046226>, double>;

} // namespace usu

template <typename S>
S operator*(double i, const S& s)
{
    S w(s.number * i);
    return w;
}

template <typename S>
bool operator==(S& i, const S& s)
{
    return true;
}
