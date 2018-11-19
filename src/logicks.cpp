//ligicks.cpp

/*  **В этом файле будет прописана основная логика изменения поля.**

1. Неактивный пользователь устанавливает приложение, если им пользуются больше 2х и меньше 5-ти знакомых, с
вероятностью 50%
2. Если пользователь не пользуется приложением, то с шансом 3% он начнет им пользоваться.
3. Если пользователь уже пользуется приложением, и 2 или 3 его знакомых также пользуются этим приложением,
то с вероятностью 85% он продолжает пользоваться этим приложением.
4. Если пользователь пользуется приложением, и менее 2-х или больше 3-х его знакомых также пользуются
этим приложением, то с вероятностью 30% он перестанет пользоваться этим приложением.


*/

#include "include/map.h"
#include <random>
#include <time.h>

#include <iostream>
#include <fstream>


void Community::startResearch(unsigned int count_of_iterations)
{
    srand(time(0));
    std::ofstream iters_logs;
    iters_logs.open("iter_logs.txt");   //файл для логов "Номер_Итерации | количество активных полльзователей"

    std::ofstream logs;
    logs.open("logs.txt");              //файл для логов общего вида "НОМЕР_ИТЕРАЦИИ | НОМЕР_ПОЛЬЗОВАТЕЛЯ"
                                    //СОСТОЯНИЕ ПОЛЬЗОВАТЕЛЯ | КОЛИЧЕСТВО_ДРУЗЕЙ | КОЛИЧЕСТВО_АКТИВНЫХ_ДРУЗЕЙ"

    for (unsigned int iters = 0; iters < count_of_iterations; iters++) //цикл по итерациям
    {
        for (int i = 0; i < count_of_users; i++)                        //цикл по пользователям
        {
            if (Users[i].state == PREPARED_TO_BE_ACTIVATED)
            {
                Users[i].state = ACTIVE;
                count_of_active_users++;
            }

            if (Users[i].state == PREPARED_TO_BE_DELETED)
            {
                Users[i].state = EMPTY;
                count_of_active_users--;
            }

            logs << iters << " "         << i
                 << " "            << Users[i].state
                 << " "             << CountOfActiveFriends(Users[i])
                 << " " << Users[i].ids_of_friends.size()
                 << " " << count_of_active_users << std::endl;
//*******************************************************************************************

            if (Users[i].state == ACTIVE)
            {
                if (CountOfActiveFriends(Users[i]) == 2 || CountOfActiveFriends(Users[i]) == 3)
                {
                    int probability = rand() % 100;
                    if (probability < 15)
                    {
                        Users[i].state = PREPARED_TO_BE_DELETED;
                    }
                    continue;
                }

                if (CountOfActiveFriends(Users[i]) < 2 || CountOfActiveFriends(Users[i]) > 3)
                {
                    int probability = rand() % 100;
                    if (probability < 30)
                    {
                        Users[i].state = PREPARED_TO_BE_DELETED;
                    }
                    continue;
                }
            }

            if (Users[i].state == EMPTY)
            {
                if (CountOfActiveFriends(Users[i]) > 2 && CountOfActiveFriends(Users[i]) < 5)
                {
                    int probability = rand() % 100;
                    if (probability < 50)
                    {
                        Users[i].state = PREPARED_TO_BE_ACTIVATED;
                    }
                    continue;
                }

                int probability = rand() % 100;
                if (probability < 3)
                {
                    Users[i].state = PREPARED_TO_BE_ACTIVATED;
                }
                continue;

            }
            //*******************************************************************************************

            logs << std::endl;

        }
        iters_logs << iters << " " << count_of_active_users << std::endl;
    }
    logs.close();
    iters_logs.close();
}
