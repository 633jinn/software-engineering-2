#include <string>
#include <list>

#include "control.h"
using namespace std;

SignIn::SignIn(/* args */)
{
    signInBoundary = new SigninUI(this);
}

SignIn::~SignIn()
{
    delete signInBoundary;
}

void SignIn::addNewMember(string id, string password, string phoneNumber)
{
    memberList.push_back(Member(id, password, phoneNumber));
}