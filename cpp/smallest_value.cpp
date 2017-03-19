#include<iostream>
#include<vector>
#include<algorithm>


int smallest_non_constructable_amount(std::vector<int> coins)
{

    std::sort(coins.begin(), coins.end());
    int max_value = 0;

    for (auto a : coins)
    {
        if (a > max_value + 1)
        {
            break;
        }

        max_value += a;
    }

    return max_value + 1;
}




int main()
{

    std::vector<int> c = {1,1,1,1,1,5,10,25};
#if 1
    std::cout << "Given coins:" << std::endl;
    for (auto a : c)
    {
        std::cout << a << ", ";
    }

    std::cout << std::endl;

    std::cout << "Smallest non-constructable amount:" << smallest_non_constructable_amount(c) << std::endl;
#endif

    return 0;
}

