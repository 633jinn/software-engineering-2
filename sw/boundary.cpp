#include "boundary.h"
#include "entity.h"
using namespace std;

SigninUI::SigninUI(SignIn *signIn)
{
    this->signIn = signIn;
}

SigninUI::~SigninUI()
{
}

void SigninUI::signInAccount(ifstream &in_fp, ofstream &out_fp)
{
    in_fp >> id >> password >> phoneNumber;
    Member *member = signIn->addNewMember(id, password, phoneNumber);
    writeOutput(out_fp, member);
}

void SigninUI::writeOutput(ofstream &out_fp, Member *member)
{
    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << member->getId() << " " << member->getPassword() << " " << member->getPhoneNumber() << endl;
}

LoginUI::LoginUI(Login *login)
{
    this->login = login;
}

LoginUI::~LoginUI()
{
}

void LoginUI::loginAccount(ifstream &in_fp, ofstream &out_fp)
{
    in_fp >> id >> password;
    User *user = login->login(id, password);
    if (user)
    {
        writeOutput(out_fp, user);
    }
}

void LoginUI::writeOutput(ofstream &out_fp, User *user)
{
    out_fp << "2.1. 로그인" << endl;
    out_fp << "> " << user->getId() << " " << user->getPassword() << endl;
}
