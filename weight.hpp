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

        W WeightRatio;
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
        ToWeight t;
        std::cout << w.number << std::endl;
        // math
        return t;
    }

    using microgram = Weight<double, std::ratio<1, 1000>>;
    using kilogram = Weight<double, std::ratio<1000, 1>>;
    using gram = Weight<double, std::ratio<1, 1>>;
    using ton = Weight<double, std::ratio<110231, 100000000000>>;
    using ounce = Weight<double, std::ratio<35274, 1000000>>;
    using pound = Weight<double, std::ratio<220462, 100000000>>;

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
