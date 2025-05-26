#ifndef SESSION_H
#define SESSION_H

#include "user.h"

class Session
{
private:
    User *loginUser;

public:
    Session();
    ~Session();
    void setLoginUser(User *user);
    User *getLoginUser();
    void logoutUser();
};

#endif