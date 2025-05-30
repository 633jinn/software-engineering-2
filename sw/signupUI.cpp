﻿#include <fstream>
#include <iostream>

#include "signupUI.h"
#include "signupControl.h"
#include "member.h"
using namespace std;

SignUpUI::SignUpUI(SignUp *signUp)
{
    this->signUp = signUp;
}

SignUpUI::~SignUpUI()
{
}

void SignUpUI::readInput(ifstream &in_fp)
{
    in_fp >> id >> password >> phoneNumber;
}

void SignUpUI::signUpAccount(ifstream &in_fp, ofstream &out_fp)
{
    readInput(in_fp);
    Member *member = signUp->addNewMember(id, password, phoneNumber);
    writeOutput(out_fp, member);
}

void SignUpUI::writeOutput(ofstream &out_fp, Member *member)
{
    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << member->getId() << " " << member->getPassword() << " " << member->getPhoneNumber() << endl
           << endl;
}