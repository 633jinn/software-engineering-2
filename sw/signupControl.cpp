#include "signupControl.h"
#include "signupUI.h"
#include "member.h"
#include "database.h"
using namespace std;

SignUp::SignUp(Database *database)
{
    this->database = database;
    signupUI = new SignUpUI(this);
}

SignUp::~SignUp()
{
    delete signupUI;
}

void SignUp::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    signupUI->signUpAccount(in_fp, out_fp);
}

Member *SignUp::addNewMember(string id, string password, string phoneNumber)
{
    Member *member = database->addMember(id, password, phoneNumber);
    return member;
}