#include<iostream>

namespace usu
{
    template <typename Rep, typename W = std::ratio<1>>
    class Weight
    {
        public:
            Weight(Rep newCount) : number(newCount) {};

            W WeightRatio;
            Rep number;

            Rep count()
            {
                return number;
            }

            template <typename S>
            Weight& operator+(S s)
            {
                Weight<double> newS(1000);
                return newS;
            }

            template <typename S>
            Weight& operator-(S s)
            {
                Weight<double> newS(1000);
                return newS;
            }

            template <typename S>
            Weight& operator=(S s)
            {
                Weight<double> newS(1000);
                return newS;
            }

            template <typename S>
            Weight& operator*(S s)
            {
                Weight<double> newS(1000);
                return newS;
            }

            template <typename S>
            bool operator==(const S& rhs)
            {
                return true;
            }

            template <typename S>
            bool operator<=(S s)
            {
                return true;
            }

            template <typename S>
            bool operator<(S s)
            {
                return true;
            }

            template <typename S>
            bool operator>=(S s)
            {
                return true;
            }

            template <typename S>
            bool operator>(S s)
            {
                return true;
            }

            template <typename S>
            bool operator!=(S s)
            {
                return true;
            }
    };

    template <typename T, typename W>
    T weight_cast(W w)
    {
        T t;
        // math
        return t;
    }

    using microgram = Weight<double , std::ratio<1, 1000>>;
    using kilogram = Weight<double , std::ratio<1000, 1>>;
    using gram = Weight<double , std::ratio<1, 1>>;
    using ton = Weight<double , std::ratio<110231, 100000000000>>;
    using ounce = Weight<double , std::ratio<35274, 1000000>>;
    using pound = Weight<double , std::ratio<220462, 100000000>>;

}

template <typename S>
S operator*(double i, const S& s)
{
    return s;
}
