#include "control.h"
using namespace std;

SignIn::SignIn()
{
    signInUI = new SigninUI(this);
}

SignIn::~SignIn()
{
    delete signInUI;
}

void SignIn::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    signInUI->signInAccount(in_fp, out_fp);
}

Member *SignIn::addNewMember(string id, string password, string phoneNumber)
{
    Member *member = new Member(id, password, phoneNumber);
    Database::addMember(member);
    return member;
}

Login::Login()
{
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
    User *user = Database::findUser(id, password);
    if (user)
    {
        Session::setLoginUser(user);
        return user;
    }
    return nullptr;
}
