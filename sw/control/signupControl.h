#ifndef SIGNUP_CONTROL_H
#define SIGNUP_CONTROL_H

#include <string.h>
#include <fstream>
#include <list>

#include "../forward.h"
#include "../boundary/signupUI.h"
#include "../entity/database.h"
#include "../entity/member.h"
using namespace std;
// 회원 가입
class SignUp
{
private:
    SignUpUI *signupUI;
    Database *database;

public:
    SignUp(Database *database);
    ~SignUp();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Member *addNewMember(string id, string password, string phoneNumber);
};

#endif