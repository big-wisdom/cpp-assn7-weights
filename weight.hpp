#include <iostream>

namespace usu
{
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
        S operator+(S s)
        {
            std::cout << s.number << std::endl;
            decltype(s) w(s.number + number);
            return w;
        }

        template <typename S>
        Weight operator-(S s)
        {
            std::cout << s.number << std::endl;
            decltype(s) newS(1000);
            return newS;
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
            decltype(s) newS(s * number);
            return newS;
        }

        template <typename S>
        bool operator==(S& rhs)
        {
            std::cout << rhs.number << std::endl;
            return true;
        }

        template <typename S>
        bool operator<=(S s)
        {
            std::cout << s.number << std::endl;
            return true;
        }

        template <typename S>
        bool operator<(S s)
        {
            std::cout << s.number << std::endl;
            return true;
        }

        template <typename S>
        bool operator>=(S s)
        {
            std::cout << s.number << std::endl;
            return true;
        }

        template <typename S>
        bool operator>(S s)
        {
            std::cout << s.number << std::endl;
            return true;
        }

        template <typename S>
        bool operator!=(S s)
        {
            std::cout << s.number << std::endl;
            return true;
        }
    };

    template <typename ToWeight, typename W>
    ToWeight weight_cast(W w)
    {
        // multiplier
        ToWeight t;

        std::cout << "from " << w.weightRatio.num << ":" << w.weightRatio.den << " to " << t.weightRatio.num << ":" << t.weightRatio.den << std::endl;
        std::cout << "in-top: " << w.weightRatio.num << std::endl;
        std::cout << "in-bottom: " << w.weightRatio.den << std::endl;
        std::cout << "out-top: " << t.weightRatio.num << std::endl;
        std::cout << "out-bottom: " << t.weightRatio.den << std::endl
                  << std::endl;

        ToWeight newWeight(w.number * w.weightRatio.num * t.weightRatio.den / (w.weightRatio.den * t.weightRatio.num));
        return newWeight;
    }

    using microgram = Weight<double, std::ratio<1, 1000000>>;
    using kilogram = Weight<double, std::ratio<1000, 1>>;
    using gram = Weight<double, std::ratio<1, 1>>;
    using ton = Weight<double, std::ratio<100000000000, 110231>>;
    using ounce = Weight<double, std::ratio<1000000, 35274>>;
    using pound = Weight<double, std::ratio<100000000, 220462>>;

} // namespace usu

template <typename S>
S operator*(double i, const S& s)
{
    std::cout << i << std::endl;
    return s;
}

template <typename S>
S operator==(S& i, const S& s)
{
    std::cout << i << std::endl;
    return s;
}
