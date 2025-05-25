#include "boundary.h"
#include "entity.h"
using namespace std;

SigninUI::SigninUI(SignIn *signIn)
{
    this->signIn = signIn;
}

SigninUI::~SigninUI()
{
    delete signIn;
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
