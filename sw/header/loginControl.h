#ifndef LOGIN_CONTROL_H
#define LOGIN_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "loginUI.h"
#include "database.h"
#include "session.h"
#include "user.h"
// 로그인
class Login
{
private:
    LoginUI *loginUI;
    Database *database;
    Session *session;

public:
    Login(Database *database, Session *session);
    ~Login();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *login(string id, string password);
};

#endif