//main.cpp

#include <iostream>
#include "include/map.h"
#include <time.h>


int main()
{
    Community com(100);

    com.CreateFriendsCommunity(30, 40, 15);

    clock_t tim = clock();
    com.startResearch(10);
    tim = clock() - tim;

    std::cout << "Time is: " << tim / CLOCKS_PER_SEC << std::endl;
    system("python3 plot/graph_show.py");

    return 0;
}
