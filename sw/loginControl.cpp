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
    //loginUI�� loginAccountȣ��
    loginUI->loginAccount(in_fp, out_fp);
}

User *Login::login(string id, string password)
{
    User *user = database->findUser(id, password);
    if (user) //���̵�� �н����忡 �ش�Ǵ� user�� ������ ���
    {
        //session�� ����
        session->setLoginUser(user);
        return user;
    }
    return nullptr;
}
