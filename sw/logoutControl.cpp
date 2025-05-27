#include "logoutControl.h"
#include "logoutUI.h"
#include "database.h"
#include "session.h"
#include "user.h"

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
