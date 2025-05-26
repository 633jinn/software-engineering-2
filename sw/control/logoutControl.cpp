#include "../control/logoutControl.h"
#include "../boundary/logoutUI.h"
#include "../entity/database.h"
#include "../entity/session.h"
#include "../entity/user.h"

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

void Logout::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    logoutUI->logoutAccount(in_fp, out_fp);
}

User *Logout::logout()
{
    User *user = session->getLoginUser();
    session->logoutUser();
    return user;
}
