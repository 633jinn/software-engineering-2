#include <string>
#include <iostream>
#include "boundary.h"
using namespace std;

SigninUI::SigninUI(SignIn *signIn)
{
    this->signIn = signIn;
}

SigninUI::~SigninUI()
{
    delete signIn;
}

void SigninUI::signInAccount(string id, string password, string phoneNumber)
{
    signIn->addNewMember(id, password, phoneNumber);
    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << name << " " << SSN << " " << ID << " " << password << endl;
}
