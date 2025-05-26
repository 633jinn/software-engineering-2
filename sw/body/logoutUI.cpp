#include "../header/logoutUI.h"
#include "../header/logoutControl.h"
#include "../header/user.h"
#include <iostream>
using namespace std;

LogoutUI::LogoutUI(Logout *logout)
{
    this->logout = logout;
}

LogoutUI::~LogoutUI() {}

void LogoutUI::logoutAccount(ofstream &out_fp)
{
    User *user = logout->logout();
    writeOutput(out_fp, user);
}

void LogoutUI::writeOutput(ofstream &out_fp, User *user)
{
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << user->getId() << endl
           << endl;
}