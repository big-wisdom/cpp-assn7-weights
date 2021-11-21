#include<iostream>

namespace usu
{
    template <typename Rep, typename W = std::ratio<1>>
    class weight
    {
        public:
            weight(Rep newCount) : count(newCount) {};

            W weightRatio;
            Rep count;
    };

    using microgram = weight<int , std::ratio<1, 1000>>;
    using kilogram = weight<int , std::ratio<1000, 1>>;
    using gram = weight<int , std::ratio<1, 1>>;
    using ton = weight<int , std::ratio<110231, 100000000000>>;
    using ounce = weight<int , std::ratio<35274, 1000000>>;
    using pound = weight<int , std::ratio<220462, 100000000>>;
}
