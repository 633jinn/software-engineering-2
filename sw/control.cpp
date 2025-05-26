#include "control.h"
using namespace std;

SignIn::SignIn(Database *database)
{
    this->database = database;
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
    Member *member = database->addMember(id, password, phoneNumber);
    return member;
}

Login::Login(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
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
    User *user = database->findUser(id, password);
    if (user)
    {
        session->setLoginUser(user);
        return user;
    }
    return nullptr;
}

Logout::Logout(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
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
    User *user = session->getLoginUser();
    session->logoutUser();
    return user;
}

RegisterBicycle::RegisterBicycle(Database *database)
{
    this->database = database;
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
    Bicycle *bicycle = database->addBicycle(bicycleId, bicycleName);
    return bicycle;
}

RentBicycle::RentBicycle(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
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
    Bicycle *bicycle = database->findBicycle(bicycleId);
    if (bicycle)
    {
        User *user = session->getLoginUser();
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

CheckRentedBicycle::CheckRentedBicycle(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
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
    User *user = session->getLoginUser();
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

ExitProgram::ExitProgram(Database *database)
{
    this->database = database;
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