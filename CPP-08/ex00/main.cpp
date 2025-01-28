#include "easyfind.hpp"

int main()
{
    try
    {
        std::cout << "Testing with std::vector<int>:" << std::endl;
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i);

        std::cout << "Searching for 5: ";
        std::vector<int>::iterator itVec = easyfind(vec, 5);
        std::cout << "Found " << *itVec << std::endl;

        std::cout << "Searching for 15: ";
        itVec = easyfind(vec, 15);
        std::cout << "Found " << *itVec << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "\nTesting with std::list<int>:" << std::endl;
        std::list<int> lst;
        for (int i = 0; i < 10; i++)
            lst.push_back(i);

        std::cout << "Searching for 7: ";
        std::list<int>::iterator itList = easyfind(lst, 7);
        std::cout << "Found " << *itList << std::endl;

        std::cout << "Searching for -1: ";
        itList = easyfind(lst, -1);
        std::cout << "Found " << *itList << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
