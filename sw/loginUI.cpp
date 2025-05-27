#include "loginUI.h"
#include "loginControl.h"
#include "user.h"
#include <fstream>
#include <iostream>
using namespace std;

void LoginUI::readInput(ifstream &in_fp)
{
    in_fp >> id >> password;
}

void LoginUI::writeOutput(ofstream &out_fp, User *user)
{
    out_fp << "2.1. 로그인" << endl;
    out_fp << "> " << user->getId() << " " << user->getPassword() << endl
           << endl;
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
    readInput(in_fp);
    User *user = login->login(id, password);
    if (user)
    {
        writeOutput(out_fp, user);
    }
}