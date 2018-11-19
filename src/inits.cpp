//inits.cpp

#include <iostream>
#include <random>
#include <time.h>
#include "include/map.h"

Community::Community(unsigned int count_of_users) : Users(new User[count_of_users]), count_of_users(count_of_users), count_of_active_users(0) {}


Community::~Community()
{
    delete [] Users;
}


void Community::CreateFriendsCommunity(unsigned short chance_of_acquaintance, unsigned int chance_of_active_state, unsigned int max_count_of_friends)
{
    srand(time(0));
    for (unsigned int i = 0; i < count_of_users; i++)
    {
        short state = rand() % 100;
        if (state < chance_of_active_state)         //задание статуса, с вероятностью chance_of_active_state
        {
            Users[i].state = ACTIVE;
            count_of_active_users++;
        }
        else
        {
            Users[i].state = EMPTY;
        }

        for (unsigned j = 0; j < max_count_of_friends; j++)
        {
            unsigned int id = rand() % count_of_users;         //добавление случайных друзей
            unsigned int chance = rand() % 100;

            if (chance < chance_of_acquaintance && id != i)
            {
                Users[i].ids_of_friends.push_back(id);
            }
        }
    }
}


unsigned int Community::getCountOfActiveUsers()
{
    return count_of_active_users;
}


int Community::CountOfActiveFriends(struct User person)
{
    int count_of_active_friends = 0;
    for (int i = 0; i < person.ids_of_friends.size(); i++)
    {
        if (Users[person.ids_of_friends[i]].state == ACTIVE)
        {
            count_of_active_friends++;
        }
    }
    return count_of_active_friends;
}

