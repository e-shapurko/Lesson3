#include <iostream>
#include "try_list.h"

using namespace std;

int main()
{
    try_list<int> tl;
    tl.push_back(5);
    tl.push_back(15);
    tl.push_back(25);

    for(auto i = tl.begin(); i != tl.end(); i++)
    {
        std::cout<<*i<<std::endl;
    }

    return 0;

}
