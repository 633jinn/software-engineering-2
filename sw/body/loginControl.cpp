#include "../header/loginControl.h"
#include "../header/loginUI.h"
#include "../header/database.h"
#include "../header/session.h"
#include "../header/user.h"

Login::Login(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
    loginUI = new LoginUI(this);
}

Login::~Login()
{
    delete loginUI;
}

void Login::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    loginUI->loginAccount(in_fp, out_fp);
}

User *Login::login(string id, string password)
{
    User *user = database->findUser(id, password);
    if (user)
    {
        session->setLoginUser(user);
        return user;
    }
    return nullptr;
}
