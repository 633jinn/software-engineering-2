#ifndef LOGOUT_UI_H
#define LOGOUT_UI_H

#include <string>
#include <fstream>
#include "../forward.h"
using namespace std;

class LogoutUI
{
private:
    Logout *logout;
    void writeOutput(ofstream &out_fp, User *user);

public:
    LogoutUI(Logout *logout);
    ~LogoutUI();
    void logoutAccount(ifstream &in_fp, ofstream &out_fp);
};

#endif