#ifndef FORWARD_H
#define FORWARD_H

// Entity
class User;
class Member;
class Manager;
class Bicycle;
class BicycleCollection;
class Database;
class Session;

// Control
class SignUp;
class Login;
class Logout;
class RegisterBicycle;
class RentBicycle;
class CheckRentedBicycle;
class ExitProgram;

// Boundary
class SignUpUI;
class LoginUI;
class LogoutUI;
class RegisterBicycleUI;
class RentBicycleUI;
class CheckRentedBicycleUI;
class ExitProgramUI;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#endif