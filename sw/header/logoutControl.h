#ifndef LOGOUT_CONTROL_H
#define LOGOUT_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "logoutUI.h"
#include "database.h"
#include "session.h"
#include "user.h"
// 로그아웃
class Logout
{
private:
    LogoutUI *logoutUI;
    Database *database;
    Session *session;

public:
    Logout(Database *database, Session *session);
    ~Logout();
    void startInterface(ofstream &out_fp);
    User *logout();
};

#endif