#ifndef FORWARD_H
#define FORWARD_H

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 전방 선언
class SignIn;
class Login;
class Logout;
class RegisterBicycle;
class RentBicycle;
class CheckRentedBicycle;
class ExitProgram;
class SigninUI;
class LoginUI;
class LogoutUI;
class RegisterBicycleUI;
class RentBicycleUI;
class CheckRentedBicycleUI;
class ExitProgramUI;
// 헤더 선언
#include <string.h>
#include <fstream>
#include <list>

// 함수 선언
void doTask();
void join();
void program_exit();
#endif