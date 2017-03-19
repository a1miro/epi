#include <iostream>
#include <vector>
#include <cstdint>
#include <map>

namespace one {

    class Uint32_t
    {

        public:
            Uint32_t():_value(0){;}
            Uint32_t(const Uint32_t& num) 
            {
                _value = num.value();
            }
            Uint32_t& operator=(Uint32_t& num)
            {
                this->_value = num.value();
                return *this;
            }
            Uint32_t(uint32_t value):_value(value){}

            uint32_t value() const { return _value;}

            std::int32_t get_ones(std::vector<::uint32_t>&  ones) const
            {
                uint32_t number = _value;
                uint32_t mask = 0;
                int32_t count = 0;

                while (number != 0)
                {
                    mask = number & ~(number - 1);
                    ones.push_back(Uint32_t::MASK_TO_POS[mask]);
                    count ++;
                    number |= ~mask;
                }

                return count;
            }



        public:
            static std::map<uint32_t, uint32_t> MASK_TO_POS;


        private:
            uint32_t _value;

    };



   std::map<uint32_t, uint32_t> Uint32_t::MASK_TO_POS = {
       {1<<0, 0},
       {1<<1, 1},
       {1<<2, 2},
       {1<<3, 3},
       {1<<4, 4},
       {1<<5, 5},
       {1<<6, 6},
       {1<<7, 7},
       {1<<8, 8},
       {1<<9, 9},
       {1<<10, 10},
       {1<<11, 11},
       {1<<12, 12},
       {1<<13, 13},
       {1<<14, 14},
       {1<<15, 15},
       {1<<16, 16},
       {1<<17, 17},
       {1<<18, 18},
       {1<<19, 19},
       {1<<20, 20},
       {1<<21, 21},
       {1<<22, 22},
       {1<<23, 23},
       {1<<24, 24},
       {1<<25, 25},
       {1<<26, 26},
       {1<<27, 27},
       {1<<28, 28},
       {1<<29, 29},
       {1<<30, 30},
       {1<<31, 31},
   };





} // namespace one

int main()
{
    one::Uint32_t number(0b01011001);
    std::vector<::uint32_t> ones;
    std::cout << "Number of ones:" << number.get_ones(ones) << std::endl;

    std::cout << "One found at: ";
    for (auto i : ones)
    {
        std::cout << i  << ", ";

    }
    std::cout << std::endl;

    return 0;
}
