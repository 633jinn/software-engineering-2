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
    out_fp << "> " << member->getId() << " " << member->getPassword() << " " << member->getPhoneNumber() << endl
           << endl;
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
    in_fp >> id >> password;
    User *user = login->login(id, password);
    if (user)
    {
        writeOutput(out_fp, user);
    }
}

void LogoutUI::writeOutput(ofstream &out_fp, User *user)
{
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << user->getId() << endl
           << endl;
}

LogoutUI::LogoutUI(Logout *logout)
{
    this->logout = logout;
}

LogoutUI::~LogoutUI()
{
}

void LogoutUI::logoutAccount(ifstream &in_fp, ofstream &out_fp)
{
    User *user = logout->logout();
    writeOutput(out_fp, user);
}

RegisterBicycleUI::RegisterBicycleUI(RegisterBicycle *registerBicycle)
{
    this->registerBicycle = registerBicycle;
}

RegisterBicycleUI::~RegisterBicycleUI()
{
}

void RegisterBicycleUI::registerBicycleInfo(ifstream &in_fp, ofstream &out_fp)
{
    in_fp >> bicycleId >> bicycleName;
    Bicycle *bicycle = registerBicycle->registerBicycle(bicycleId, bicycleName);
    writeOutput(out_fp, bicycle);
}

void RegisterBicycleUI::writeOutput(ofstream &out_fp, Bicycle *bicycle)
{
    out_fp << "3.1. 자전거 등록" << endl;
    out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl
           << endl;
}

void RentBicycleUI::writeOutput(ofstream &out_fp, Bicycle *bicycle)
{
    out_fp << "4.1. 자전거 대여" << endl;
    out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl
           << endl;
}

RentBicycleUI::RentBicycleUI(RentBicycle *rentBicycle)
{
    this->rentBicycle = rentBicycle;
}

RentBicycleUI::~RentBicycleUI()
{
}

void RentBicycleUI::rentBicycleInfo(ifstream &in_fp, ofstream &out_fp)
{
    in_fp >> bicycleId;
    Bicycle *bicycle = rentBicycle->rentBicycle(bicycleId);
    if (bicycle)
    {
        writeOutput(out_fp, bicycle);
    }
}

void CheckRentedBicycleUI::writeOutput(ofstream &out_fp, list<Bicycle *> rentedBicycle)
{
    out_fp << "5.1. 자전거 대여 리스트" << endl;
    for (auto bicycle : rentedBicycle)
    {
        out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl;
    }
    out_fp << endl;
}

CheckRentedBicycleUI::CheckRentedBicycleUI(CheckRentedBicycle *checkRentedBicycle)
{
    this->checkRentedBicycle = checkRentedBicycle;
}

CheckRentedBicycleUI::~CheckRentedBicycleUI()
{
}

void CheckRentedBicycleUI::checkRentedInfo(ofstream &out_fp)
{
    list<Bicycle *> rentedBicycle = checkRentedBicycle->checkRentedList();
    writeOutput(out_fp, rentedBicycle);
}

void ExitProgramUI::writeOutput(ofstream &out_fp)
{
    out_fp << "6.1. 종료" << endl;
}

ExitProgramUI::ExitProgramUI(ExitProgram *exitProgram)
{
    this->exitProgram = exitProgram;
}

ExitProgramUI::~ExitProgramUI()
{
}

void ExitProgramUI::exit(ofstream &out_fp)
{
    writeOutput(out_fp);
}
