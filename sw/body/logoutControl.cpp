#include "../header/logoutControl.h"
#include "../header/logoutUI.h"
#include "../header/database.h"
#include "../header/session.h"
#include "../header/user.h"

Logout::Logout(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
    logoutUI = new LogoutUI(this);
}

Logout::~Logout()
{
    delete logoutUI;
}

void Logout::startInterface(ofstream &out_fp)
{
    logoutUI->logoutAccount(out_fp);
}

User *Logout::logout()
{
    User *user = session->getLoginUser();
    session->logoutUser();
    return user;
}
