#include "control.h"
using namespace std;

SignIn::SignIn()
{
    signInUI = new SigninUI(this);
}

SignIn::~SignIn()
{
    delete signInUI;
}

void SignIn::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    signInUI->signInAccount(in_fp, out_fp);
}

Member *SignIn::addNewMember(string id, string password, string phoneNumber)
{
    Member *member = Database::addMember(id, password, phoneNumber);
    return member;
}

Login::Login()
{
    loginUI = new LoginUI(this);
}

Login::~Login()
{
    delete loginUI;
}

void Login::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    loginUI->loginAccount(in_fp, out_fp);
}

User *Login::login(string id, string password)
{
    User *user = Database::findUser(id, password);
    if (user)
    {
        Session::setLoginUser(user);
        return user;
    }
    return nullptr;
}

Logout::Logout()
{
    logoutUI = new LogoutUI(this);
}

Logout::~Logout()
{
    delete logoutUI;
}

void Logout::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    logoutUI->logoutAccount(in_fp, out_fp);
}

User *Logout::logout()
{
    User *user = Session::getLoginUser();
    Session::logoutUser();
    return user;
}

RegisterBicycle::RegisterBicycle()
{
    registerBicycleUI = new RegisterBicycleUI(this);
}

RegisterBicycle::~RegisterBicycle()
{
    delete registerBicycleUI;
}

void RegisterBicycle::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    registerBicycleUI->registerBicycleInfo(in_fp, out_fp);
}

Bicycle *RegisterBicycle::registerBicycle(string bicycleId, string bicycleName)
{
    Bicycle *bicycle = Database::addBicycle(bicycleId, bicycleName);
    return bicycle;
}

RentBicycle::RentBicycle()
{
    rentBicycleUI = new RentBicycleUI(this);
}

RentBicycle::~RentBicycle()
{
    delete rentBicycleUI;
}

void RentBicycle::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    rentBicycleUI->rentBicycleInfo(in_fp, out_fp);
}

Bicycle *RentBicycle::rentBicycle(string bicycleId)
{
    Bicycle *bicycle = Database::findBicycle(bicycleId);
    if (bicycle)
    {
        User *user = Session::getLoginUser();
        if (user)
        {
            Member *member = dynamic_cast<Member *>(user);
            if (member)
            {
                member->getBicycleCollection()->addRentedBicycle(bicycle);
                return bicycle;
            }
        }
    }
    return nullptr;
}

CheckRentedBicycle::CheckRentedBicycle()
{
    checkRentedBicycleUI = new CheckRentedBicycleUI(this);
}

CheckRentedBicycle::~CheckRentedBicycle()
{
    delete checkRentedBicycleUI;
}

void CheckRentedBicycle::startInterface(ofstream &out_fp)
{
    checkRentedBicycleUI->checkRentedInfo(out_fp);
}

list<Bicycle *> CheckRentedBicycle::checkRentedList()
{
    User *user = Session::getLoginUser();
    if (user)
    {
        Member *member = dynamic_cast<Member *>(user);
        if (member)
        {
            return member->getBicycleCollection()->getRentedList();
        }
    }
    return list<Bicycle *>();
}

ExitProgram::ExitProgram()
{
    exitProgramUI = new ExitProgramUI(this);
}

ExitProgram::~ExitProgram()
{
    delete exitProgramUI;
}

void ExitProgram::startInterface(ofstream &out_fp)
{
    exitProgramUI->exit(out_fp);
}