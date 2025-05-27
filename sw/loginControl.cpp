#include "loginControl.h"
#include "loginUI.h"
#include "database.h"
#include "session.h"
#include "user.h"

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
    //loginUI의 loginAccount호출
    loginUI->loginAccount(in_fp, out_fp);
}

User *Login::login(string id, string password)
{
    User *user = database->findUser(id, password);
    if (user) //아이디와 패스워드에 해당되는 user가 존재할 경우
    {
        //session에 저장
        session->setLoginUser(user);
        return user;
    }
    return nullptr;
}
