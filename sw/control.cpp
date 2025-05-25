#include "control.h"
using namespace std;

SignIn::SignIn(UserDB *userDB)
{
    this->userDB = userDB;
    signInBoundary = new SigninUI(this);
}

SignIn::~SignIn()
{
    delete signInBoundary;
}

void SignIn::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    signInBoundary->signInAccount(in_fp, out_fp);
}

Member* SignIn::addNewMember(string id, string password, string phoneNumber)
{
    Member* member = new Member(id, password, phoneNumber);
    userDB->addMember(member);
    return member;
}