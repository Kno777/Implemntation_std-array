#include <iostream>
#include "array.h"

int main()
{
    array<int,3> myArray{12,34,56};
    for(int i = 0; i < 3; ++i)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << myArray.front() << std::endl;
    std::cout << myArray.back() << std::endl;
    std::cout << myArray.at(1) << std::endl;
    std::cout << myArray.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << *myArray.begin() << std::endl;
    array<int,3>::iterator it;

    it = myArray.begin();
    for(it; it != myArray.end(); ++it)
    {
        std::cout << *it << " ";
    }
}