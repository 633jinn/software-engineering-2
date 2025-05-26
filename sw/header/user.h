#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
protected:
    string id;
    string password;

public:
    virtual ~User() {}
    string getId() { return id; }
    string getPassword() { return password; }
    bool isValid(string id, string password)
    {
        if (id == this->id && password == this->password)
            return true;
        return false;
    }
};

#endif