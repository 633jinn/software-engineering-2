#include "../header/session.h"

Session::Session()
{
    loginUser = nullptr;
}

Session::~Session() {}

void Session::setLoginUser(User *user)
{
    loginUser = user;
}

User *Session::getLoginUser()
{
    return loginUser;
}

void Session::logoutUser()
{
    loginUser = nullptr;
}