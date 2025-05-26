#ifndef LOGOUT_CONTROL_H
#define LOGOUT_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "../forward.h"
#include "../boundary/logoutUI.h"
#include "../entity/database.h"
#include "../entity/session.h"
#include "../entity/user.h"
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
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *logout();
};

#endif