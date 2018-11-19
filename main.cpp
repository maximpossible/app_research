//main.cpp

#include <iostream>
#include "map.h"
#include <time.h>


int main()
{
    Community com(1000000);

    com.CreateFriendsCommunity(30, 40, 15);

    clock_t tim = clock();
    com.startResearch(10);
    tim = clock() - tim;

    std::cout << "Time is: " << tim / CLOCKS_PER_SEC << std::endl;
    system("python3 graph_show.py");

    return 0;
}