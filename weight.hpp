#include <iostream>

namespace usu
{
    template <typename ToWeight, typename W>
    ToWeight weight_cast(W w)
    {
        ToWeight t;
        ToWeight newWeight(w.number * w.weightRatio.num * t.weightRatio.den / (w.weightRatio.den * t.weightRatio.num));
        return newWeight;
    }

    template <typename Rep, typename W = std::ratio<1>>
    class Weight
    {
      public:
        Weight() :
            number(0){};

        Weight(Rep newCount) :
            number(newCount){};

        W weightRatio;
        Rep number;

        Rep count()
        {
            return number;
        }

        template <typename S>
        Weight operator+(S s)
        {
            Weight w(s.number + number);
            return w;
        }

        template <typename S>
        Weight operator-(S s)
        {
            Weight w(number - s.number);
            return w;
        }

        template <typename S>
        Weight operator=(S s)
        {
            std::cout << s.number << std::endl;
            Weight<double> newS(1000);
            return newS;
        }

        template <typename S>
        Weight operator*(S s)
        {
            Weight newS(s * number);
            return newS;
        }

        template <typename S>
        bool operator==(S& rhs)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(rhs);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return std::abs(nrhs.number - newThis.number) < 0.00001;
        }

        template <typename S>
        bool operator<=(S s)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(s);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return nrhs.number - newThis.number > -1 * 0.0004;
        }

        template <typename S>
        bool operator<(S s)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(s);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return nrhs.number - newThis.number > 0.00001;
        }

        template <typename S>
        bool operator>=(S s)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(s);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return nrhs.number - newThis.number < 0.00001;
        }

        template <typename S>
        bool operator>(S s)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(s);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return nrhs.number - newThis.number < -1 * 0.00001;
        }

        template <typename S>
        bool operator!=(S s)
        {
            auto nrhs = weight_cast<Weight<double, std::ratio<1, 1>>>(s);
            auto newThis = weight_cast<Weight<double, std::ratio<1, 1>>>(*this);

            return std::abs(nrhs.number - newThis.number) > 0.00001;
        }
    };

    using microgram = Weight<double, std::ratio<1, 1000000>>;
    using kilogram = Weight<double, std::ratio<1000, 1>>;
    using gram = Weight<double, std::ratio<1, 1>>;
    using ton = Weight<double, std::ratio<100000000, 11>>;
    // using ton = Weight<double, std::ratio<100000000000, 98421>>;
    using ounce = Weight<double, std::ratio<100000000000, 3527396195>>;
    using pound = Weight<double, std::ratio<10000000000, 22046226>>;

} // namespace usu

template <typename S>
S operator*(double i, const S& s)
{
    S w(s.number * i);
    return w;
}

template <typename S>
S operator==(S& i, const S& s)
{
    std::cout << i << std::endl;
    return s;
}
