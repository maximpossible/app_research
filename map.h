//map.h

#include <vector>

enum CONDITION {EMPTY, ACTIVE, PREPARED_TO_BE_ACTIVATED, PREPARED_TO_BE_DELETED};

struct User
{
    CONDITION state = EMPTY;
    std::vector <int> ids_of_friends;
};


class Community
{
private:
    struct User* Users;
    unsigned int count_of_users;
    unsigned int count_of_active_users;
public:
    Community(unsigned int = 10);
    ~Community();
    unsigned int GetCountOfUsers();
    void CreateFriendsCommunity(unsigned short = 20, unsigned int = 20, unsigned int = 30);
    unsigned int getCountOfActiveUsers();
    int CountOfActiveFriends(struct User);
    void startResearch(unsigned int = 1000); //сколько все таки итераций
};
