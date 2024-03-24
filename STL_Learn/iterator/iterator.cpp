
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vector = { 11,4,5,1,4,1,9,1,9,8,1,0 };



    auto ite_begin = vector.begin();
    auto ite_end = vector.end();


    for (; ++ite_begin != ite_end;)
    {
        std::cout << *ite_begin << std::endl;
    }

    std::cout << *ite_begin <<std::endl;
    std::cout << *(--ite_end) << std::endl;

    std::cout << "Hello World!\n";
}
